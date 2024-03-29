#include "WhiteTeam.h"
#include "BlackTeam.h"
#include "NormalMove.h"
#include "PieceManager.h"
#include "TeamManager.h"
#include "WhiteTeamFactory.h"

WhiteTeam::WhiteTeam(Table table) : Team(table) {
	this->_teamFactory = new WhiteTeamFactory();
	this->init();
}

WhiteTeam::WhiteTeam(const WhiteTeam& other) : Team(other) {}

void WhiteTeam::init() {
	this->pieces = this->_teamFactory->createTeam();
}

void WhiteTeam::checkKingSideCastling(Team* other) {
	// White Team is in check
	if (other->isCheck()) {
		return;
	}

	Piece* king = this->pieces.at(12); // King 
	Piece* rook = this->pieces.at(15); // Rook

	// The rook has already been captured
	if (rook->GetCaptured()) {
		return;
	}

	// Check if either the King or the Rook is moved
	if (king->GetMoved() || rook->GetMoved()) {
		return;
	}

	// Check if the squares between the King and the Rook are empty 
	if (Utils::getPieceAt(Position(0, 5), this->_table) || 
		Utils::getPieceAt(Position(0, 6), this->_table)) 
		return;
	

	// Check if any of the square between the rook and king is not protected by the other team
	for (Position pos : other->GetValidPlaces()) {	
		if (pos == Position(0, 5) ||
			pos == Position(0, 6)) {
			return;
		}
	}

	// Add Move
	king->AddValidMove(
		new CastleMove(
			PieceDef(king->GetId(), king->GetPosition(), Position(0, 6)),
			PieceDef(rook->GetId(), rook->GetPosition(), Position(0, 5))
		)
	);
}

void WhiteTeam::checkQueenSideCastling(Team* other) {
	if (other->isCheck()) {
		return;
	}

	Piece* king = this->pieces.at(12);
	Piece* rook = this->pieces.at(8);

	// The rook has already been captured
	if (rook->GetCaptured()) {
		return;
	}

	// If either the king or the rook was previously moved
	if (king->GetMoved() || rook->GetMoved()) {
		return;
	}

	// The squares between the rook and king are not empty
	if (Utils::getPieceAt(Position(0, 3), this->_table) || 
		Utils::getPieceAt(Position(0, 2), this->_table) || 
		Utils::getPieceAt(Position(0, 1), this->_table)) {
		return;
	}

	// Check if any of the square between the rook and king is not protected by the other team
	for (Position pos : other->GetValidPlaces()) {
		if (pos == Position(0, 3) ||
			pos == Position(0, 2) ||
			pos == Position(0, 1)) {
			return;
		}
	}
	
	king->AddValidMove(
		new CastleMove(
			PieceDef(king->GetId(), king->GetPosition(), Position(0, 2)), 
			PieceDef(rook->GetId(), rook->GetPosition(), Position(0, 3))
		)
	);
}

void WhiteTeam::checkForEnPassant(int id) {
	Piece* pawn = PieceManager::GetPieceMap().at(id);
	Position pos = pawn->GetPosition();
	Move* lastMove = TeamManager::GetLastMove();

	if (pos.x == 4) {
		// Check for EnPassant left
		if (pos.y >= 1) {
			int neighbourId = Utils::getPieceAt(Position(pos.x, pos.y - 1), this->_table);

			// Chech if the neighbour is a black pawn
			if (Utils::isBlackPawn(neighbourId)) {
				Move* move = new NormalMove(PieceDef(neighbourId, Position(6, pos.y - 1), Position(4, pos.y - 1)));

				if (*move == *lastMove) {
					delete(move);

					//Add Move
					 pawn->AddValidMove(
						 new EnPassant(
							PieceDef(pawn->GetId(), pawn->GetPosition(), Position(5, pos.y - 1)),
							neighbourId, 
							Position(4, pos.y - 1)
						)
					 );
				}
			}
		}

		// Check for EnPassant Right 
		if (pos.y <= 6) {
			int neighbourId = Utils::getPieceAt(Position(pos.x, pos.y + 1), this->_table);

			// Chech if the neighbour is a black pawn
			if (Utils::isBlackPawn(neighbourId)) {
				Move* move = new NormalMove(PieceDef(neighbourId, Position(6, pos.y + 1), Position(4, pos.y + 1)));

				if (*move == *lastMove) {

					delete(move);
					
					// Add Move
					pawn->AddValidMove(
						new EnPassant(
							PieceDef(pawn->GetId(), pawn->GetPosition(), Position(5, pos.y + 1)),
							neighbourId,
							Position(4, pos.y + 1)
						)
					);
				}
			}
		}
	}
}

bool WhiteTeam::ProcessIllegalMoves(Team* other) {
	bool isGameOver = true;

	this->Clear();
	this->Update(other);
	this->UpdateKing();

	if (other->isDoubleCheck()) {
		// Only the king can be moved 
		for (Piece* p : this->pieces) {
			if (p->GetPieceType() == PieceType::KING) {
				// this->UpdateKing();
				Piece* king = PieceManager::GetPieceMap().at(13);
				if (king->GetValidMoves().size() == 0)
					return true;
			}
			else
				p->Clear();
		}
		return false;
	}

	else if (other->isCheck()) {
		// Check for king moves or ways to capture the piece
		Piece* checkPiece = other->getGivingCheckPiece()[0];
		Piece* king = PieceManager::GetPieceMap().at(13);
		Position checkPiecePosition = checkPiece->GetPosition();	

		if (king->GetValidMoves().size() != 0)
			isGameOver = false;

		// Check for pieces that could capture that piece
		for (Piece* p : this->pieces) {
			if (p->GetCaptured() || p->GetPieceType() == PieceType::KING)
				continue;

			size_t i = 0;
			while (i != p->GetValidMoves().size()) {
				Move* move = p->GetValidMoves().at(i);
				if (move->GetActualPosition() == checkPiecePosition && move->GetType() == MoveType::CAPTURE) {
					isGameOver = false;
					i++;
				}
				// Check For Pieces that could come between the king and the attacking piece
				else if (Utils::IsBetween(checkPiecePosition, king->GetPosition(), move->GetActualPosition())) {
					i++;
					isGameOver = false;
				}
		
				else 
					p->GetValidMoves().erase(p->GetValidMoves().begin() + i);
			}
		}
	}

	else {
		// No check
		this->checkKingSideCastling(other);
		this->checkQueenSideCastling(other);
		if (this->hasValidMoves())
			isGameOver = false;
	}
	return isGameOver;
}

void WhiteTeam::UpdateKing()
{
	PieceManager::GetPieceMap().at(13)->Update(this->_table);
}

void WhiteTeam::AddNewBishop(const Position& pos)
{
	Piece* bishop = _teamFactory->getNewBishop(pos);
	this->pieces.push_back(bishop);
	Utils::SetTablePosition(this->_table, pos, bishop->GetId());
}

void WhiteTeam::AddNewKnight(const Position& pos)
{
	Piece* knight = _teamFactory->getNewKnight(pos);
	this->pieces.push_back(knight);
	Utils::SetTablePosition(this->_table, pos, knight->GetId());
}

void WhiteTeam::AddNewRook(const Position& pos)
{
	Piece* rook = _teamFactory->getNewRook(pos);
	this->pieces.push_back(rook);
	Utils::SetTablePosition(this->_table, pos, rook->GetId());	
}

void WhiteTeam::AddNewQueen(const Position& pos)
{
	Piece* queen = _teamFactory->getNewQueen(pos);
	this->pieces.push_back(queen);
	Utils::SetTablePosition(this->_table, pos, queen->GetId());
}
