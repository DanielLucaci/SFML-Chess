#include "PlayState.h"
#include "Utils.h"
#include "BlackTeam.h"
#include "WhiteTeam.h"
#include "TeamManager.h"
#include <fstream>
#include "TransformBox.h"
#include "UIManager.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "TimeManager.h"
#include "PlayStateEventHandler.h"

PlayState::PlayState() : _soundManager(), _pieceManager(), _boxManager() {
	this->InitTable();
	this->ReadTable();
	timeManager->addTimer("BOX_ELAPSED_TIME");
	this->eventHandler = new PlayStateEventHandler(this);
	this->_whiteTeam = new WhiteTeam(this->_table);
	this->_blackTeam = new BlackTeam(this->_table);
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
	this->_boardTexture = sf::Sprite(assetManager->GetTexture("Table"));
}

void PlayState::HandleInput() {
	eventHandler->handleInput();
}

void PlayState::Update(float dt) {
	uiManager->Update();

	if (this->_box != nullptr && timeManager->isGreaterThan("BOX_ELAPSED_TIME", TIME_TO_DISPLAY_MESSAGE)) {
		this->_box = nullptr;
		this->_currentState = PlayStates::PLAYING;
	}

	// User didn't click anything
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) || this->_lockClick)
		return;

	// Get clicked square
	Position pos = Utils::getClickedSquare();
	
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
								window->clear();
								this->DrawBoard();
								this->DrawPieces();
								static_cast<TransformBox*>(_box)->Display();
								window->display();
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
						timeManager->resetTimer("BOX_ELAPSED_TIME");
						if(this->_turn == 0)
							this->_soundManager.PlaySound("Win");
						else 
							this->_soundManager.PlaySound("Lose");
						this->_currentState = PlayStates::CHECKMATE;
						this->_box = (this->_turn == 0) ? this->_boxManager.GetBox("White Wins") : this->_boxManager.GetBox("Black Wins");
					}
					else if (this->_isStalemate) {
						timeManager->resetTimer("BOX_ELAPSED_TIME");
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
				timeManager->resetTimer("BOX_ELAPSED_TIME");
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
				timeManager->resetTimer("BOX_ELAPSED_TIME");
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
	window->clear();

	// Draw Board
	this->DrawBoard();

	// Draw Hover square
	uiManager->Draw();

	// Draw Valid squares 
	if (this->_selectedPiece != 0) 
		uiManager->DrawValidSquares(this->_pieceManager[_selectedPiece]->GetValidMoves(), this->_table);
	

	if (this->_whiteTeam->isCheck()) {
		uiManager->DrawCheck(this->_pieceManager[29]->GetPosition());
	}
	
	if (this->_blackTeam->isCheck()) {
		uiManager->DrawCheck(this->_pieceManager[13]->GetPosition());
	}

	this->DrawPieces();

	switch (this->_currentState) {
		case PlayStates::INVALID:
		case PlayStates::STALEMATE:
		case PlayStates::CHECKMATE: 
			this->_box->Display();
			break;
		case PlayStates::TRANSFORM:
			static_cast<TransformBox*>(this->_box)->Display();
			break;
		default:
			break;
	}
	window->display();
}

void PlayState::DrawPieces() {
	PieceMap pieces = this->_pieceManager.GetPieceMap();
	for (PieceMap::const_iterator it = pieces.begin(); it != pieces.end(); it++)
		if (!it->second->GetCaptured()) 
			window->draw(it->second->GetTexture());
}

void PlayState::DrawBoard()
{
	window->draw(this->_boardTexture);
}

int PlayState::GetTurn() const
{
	return this->_turn;
}

bool& PlayState::GetLockClick()
{
	return this->_lockClick;
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


