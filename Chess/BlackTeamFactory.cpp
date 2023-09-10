#include "BlackTeamFactory.h"
#include "BlackPawn.h"
#include "BlackKnight.h"
#include "BlackBishop.h"
#include "BlackRook.h"
#include "BlackKing.h"
#include "BlackQueen.h"
#include "PieceManager.h"
	
BlackTeamFactory::BlackTeamFactory(): TeamFactory(41)
{
}

void BlackTeamFactory::addPawns()
{
	this->_pieces.insert(_pieces.end(), {
		new BlackPawn(Position(6, 0), 17), new BlackPawn(Position(6, 1), 18), new BlackPawn(Position(6, 2), 19), new BlackPawn(Position(6, 3), 20),
		new BlackPawn(Position(6, 4), 21), new BlackPawn(Position(6, 5), 22), new BlackPawn(Position(6, 6), 23), new BlackPawn(Position(6, 7), 24)
	});
}

void BlackTeamFactory::addBishops()
{
	this->_pieces.insert(_pieces.end(), { new BlackBishop(Position(7, 2), 27), new BlackBishop(Position(7, 5), 30) });
}

void BlackTeamFactory::addQueen()
{
	this->_pieces.push_back(new BlackQueen(Position(7, 3), 28));
}

void BlackTeamFactory::addKing()
{
	this->_pieces.push_back(new BlackKing(Position(7, 4), 29));
}

void BlackTeamFactory::addRooks()
{
	this->_pieces.insert(_pieces.end(), { new BlackRook(Position(7, 0), 25), new BlackRook(Position(7, 7), 32) });
}

void BlackTeamFactory::addKnights()
{
	this->_pieces.insert(_pieces.end(), { new BlackKnight(Position(7, 1), 26), new BlackKnight(Position(7, 6), 31) });
}

Piece* BlackTeamFactory::getNewBishop(const Position& pos)
{
	Piece* bishop = new BlackBishop(pos, this->_over);
	PieceManager::GetPieceMap()[this->_over++] =  bishop;
	return bishop;
}

Piece* BlackTeamFactory::getNewKnight(const Position& pos)
{
	Piece* knight = new BlackKnight(pos, this->_over);
	PieceManager::GetPieceMap()[this->_over++] = knight;
	return knight;
}

Piece* BlackTeamFactory::getNewRook(const Position& pos)
{
	Piece* rook = new BlackRook(pos, this->_over);
	PieceManager::GetPieceMap()[this->_over++] = rook;
	return rook;
}

Piece* BlackTeamFactory::getNewQueen(const Position& pos)
{
	Piece* queen = new BlackQueen(pos, this->_over);
	PieceManager::GetPieceMap()[this->_over++] = queen;
	return queen;
}