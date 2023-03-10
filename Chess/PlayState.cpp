#include "PlayState.h"
#include "Utils.h"
#include "BlackTeam.h"
#include "WhiteTeam.h"
#include "TeamManager.h"
#include <fstream>
#include "TransformBox.h"


PlayState::PlayState(GameDataRef data) : _data(data), _soundManager(data), _pieceManager(data), _boxManager(data) {
	this->InitTable();
	this->ReadTable();
	this->_whiteTeam = new WhiteTeam(data, this->_table);
	this->_blackTeam = new BlackTeam(data, this->_table);
	this->_pieceManager.LoadPieces(_whiteTeam).LoadPieces(_blackTeam);
	TeamManager::LoadTeams(this->_whiteTeam, this->_blackTeam);
	this->_currentState = PlayStates::PLAYING;
	this->_showMessage = this->_isStalemate = this->_isCheckmate = false;
	this->_turn = 0;
	this->_selectedPiece = 0;
	this->_lockClick = false;
	this->Init();
}

void PlayState::Init() {
	// Init Board Texture
	this->_boardTexture = sf::Sprite(this->_data->assets.GetTexture("Table"));
}

void PlayState::HandleInput() {
	sf::Event event;
	while (_data->window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			_data->window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left && !this->_lockClick) {
				this->Update(0.f);
				this->_lockClick = true;
			}
			break;
		case sf::Event::MouseButtonReleased: //Mouse button Released now.
			if (event.mouseButton.button == sf::Mouse::Left && this->_lockClick)
				this->_lockClick = false;
			break;
		default:
			break;
		}
	}
}

void PlayState::Update(float dt) {
	_data->ui.Update();

	if (this->_box != nullptr && this->_elapsedTimeBox.getElapsedTime().asSeconds() >= TIME_TO_DISPLAY_MESSAGE) {
		this->_box = nullptr;
		this->_currentState = PlayStates::PLAYING;
	}

	// User didn't click anything
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) || this->_lockClick)
		return;

	// Get clicked square
	Position pos = Utils::getClickedSquare(_data->window);
	
	// User clicked outside the board
	if (pos.x < 0 || pos.y < 0)
		return;

	// Extract
	int clickedPiece = Utils::getPieceAt(pos, this->_table);

	// Previous piece was chosen
	if (_selectedPiece) {
		if (Utils::isValidPiece(this->_turn, clickedPiece)) 
			this->_selectedPiece = clickedPiece;
		
		else {
			// Check for move 
			bool isMoved = false;
			for (Move* move : this->_pieceManager[_selectedPiece]->GetValidMoves()) {
				
				// User clicked a valid piece
				if (move->GetActualPosition() == pos) {

					isMoved = true;
					if (move->GetType() == MoveType::TRANSFORM) {
						this->_currentState = PlayStates::TRANSFORM;
						this->_box = this->_boxManager.GetBox("Transform Piece");
						static_cast<TransformBox*>(this->_box)->SetTurn(this->_turn);
						static_cast<TransformBox*>(this->_box)->LoadTextures();
						while (true) {
							static_cast<TransformBox*>(this->_box)->HandleInput();
							TransformedPieceType newPieceType = static_cast<TransformBox*>(this->_box)->GetChosenPiece();
							if (newPieceType != TransformedPieceType::NOPIECE) {// a piece was selected
								static_cast<TransformMove*>(move)->SetPieceType(newPieceType);
								_box = nullptr;
								break;
							}
							else {
								static_cast<TransformBox*>(this->_box)->Update(dt);
								_data->window->clear();
								this->DrawBoard();
								this->DrawPieces();
								static_cast<TransformBox*>(_box)->Display(_data->window);
								_data->window->display();
							}
						}
					}
					this->MovePiece(move);
					TeamManager::AddMove(move);

					this->_currentState = PlayStates::PLAYING;

					switch (this->_turn) {
						case 0: // White
							_whiteTeam->Update(_blackTeam);
							this->_isCheckmate = _blackTeam->ProcessIllegalMoves(_whiteTeam) && _whiteTeam->isCheck();
							_whiteTeam->UpdateKing();
							std::cout << this->_isCheckmate << '\n';
							if (!_blackTeam->hasValidMoves())
								this->_isStalemate = true;
							break;
						case 1: // Black
							_blackTeam->Update(_whiteTeam);
							this->_isCheckmate = _whiteTeam->ProcessIllegalMoves(_blackTeam) && _blackTeam->isCheck();
							_blackTeam->UpdateKing();
							std::cout << this->_isCheckmate << '\n';
							if (!_whiteTeam->hasValidMoves())
								this->_isStalemate = true;
							break;
						default:
							break;
					}

					if (this->_isCheckmate) {
						this->_elapsedTimeBox.restart();
						if(this->_turn == 0)
							this->_soundManager.PlaySound("Win");
						else 
							this->_soundManager.PlaySound("Lose");
						this->_currentState = PlayStates::CHECKMATE;
						this->_box = (this->_turn == 0) ? this->_boxManager.GetBox("White Wins") : this->_boxManager.GetBox("Black Wins");
					}
					else if (this->_isStalemate) {
						this->_elapsedTimeBox.restart();
						this->_currentState = PlayStates::STALEMATE;
						this->_box = this->_boxManager.GetBox("Stalemate");
					}
					else {
						this->makeSound(move);
					}
					this->_turn = 1 - this->_turn;
					break;
				}
			}

			if (isMoved == false) {
				this->_elapsedTimeBox.restart();
				this->_currentState = PlayStates::INVALID;
				this->_soundManager.PlaySound("Invalid");
				this->_box = this->_boxManager.GetBox("Invalid Move");
			}
			this->_selectedPiece = 0;
		}
	}

	// No piece selected previously
	else {
		if (!clickedPiece)
			return;

		else {
			if (!Utils::isValidPiece(this->_turn, clickedPiece)) {
				this->_elapsedTimeBox.restart();
				this->_selectedPiece = 0;
				this->_box = this->_boxManager.GetBox("Invalid Piece");
				this->_soundManager.PlaySound("Invalid");
				this->_currentState = PlayStates::INVALID;
			}
			else
				this->_selectedPiece = clickedPiece;
		}
	}
}

void PlayState::Draw(float dt) {
	_data->window->clear();

	// Draw Board
	this->DrawBoard();

	// Draw Hover square
	_data->ui.Draw();

	// Draw Valid squares 
	if (this->_selectedPiece != 0) 
		_data->ui.DrawValidSquares(this->_pieceManager[_selectedPiece]->GetValidMoves(), this->_table);
	

	if (this->_whiteTeam->isCheck()) {
		_data->ui.DrawCheck(this->_pieceManager[29]->GetPosition());
	}
	
	if (this->_blackTeam->isCheck()) {
		_data->ui.DrawCheck(this->_pieceManager[13]->GetPosition());
	}

	this->DrawPieces();

	switch (this->_currentState) {
		case PlayStates::INVALID:
		case PlayStates::STALEMATE:
		case PlayStates::CHECKMATE: 
			this->_box->Display(this->_data->window);
			break;
		case PlayStates::TRANSFORM:
			static_cast<TransformBox*>(this->_box)->Display(_data->window);
			break;
		default:
			break;
	}
	_data->window->display();
}

void PlayState::DrawPieces() {
	PieceMap pieces = this->_pieceManager.GetPieceMap();
	for (PieceMap::const_iterator it = pieces.begin(); it != pieces.end(); it++)
		if (!it->second->GetCaptured()) 
			_data->window->draw(it->second->GetTexture());
}

void PlayState::DrawBoard()
{
	_data->window->draw(this->_boardTexture);
}

int PlayState::GetTurn() const
{
	return this->_turn;
}


void PlayState::PrintTable() {
	std::cout << '\n';
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) 
			std::cout << this->_table[i][j] << " ";
		std::cout << '\n';
	}
}

void PlayState::ReadTable()
{
	std::ifstream fin("table.ini");
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			fin >> this->_table[i][j];
	fin.close();
}

void PlayState::InitTable() {
	// Init table 
	this->_table = new int* [8];
	for (int i = 0; i < 8; i++)
		this->_table[i] = new int[8];
}

void PlayState::MovePiece(Move* move)
{
	move->makeMove(this->_table);
}

void PlayState::makeSound(Move* move) 
{
	switch (move->GetType()) {
		case MoveType::NORMAL:
			if (_whiteTeam->isCheck() || _blackTeam->isCheck()) {
				this->_soundManager.PlaySound("Check");
				break;
			}
		case MoveType::CASTLE:
			this->_soundManager.PlaySound("Move");
			break;
		case MoveType::ENPASSANT:
		case MoveType::CAPTURE:
			this->_soundManager.PlaySound("Capture");
			break;
		case MoveType::TRANSFORM:
			break;
		default:
			break;
	}
}


