#include "WhiteTeamFactory.h"
#include "WhitePawn.h"
#include "WhiteKnight.h"
#include "WhiteBishop.h"
#include "WhiteRook.h"
#include "WhiteKing.h"
#include "WhiteQueen.h"
#include "WhiteTeamFactory.h"
#include "PieceManager.h"

WhiteTeamFactory::WhiteTeamFactory(): TeamFactory(33)
{
}

void WhiteTeamFactory::addPawns()
{
	_pieces.insert(_pieces.end(), {
		new WhitePawn(Position(1, 0), 1), new WhitePawn(Position(1, 1), 2), new WhitePawn(Position(1, 2), 3), new WhitePawn(Position(1, 3), 4),
		new WhitePawn(Position(1, 4), 5), new WhitePawn(Position(1, 5), 6), new WhitePawn(Position(1, 6), 7), new WhitePawn(Position(1, 7), 8)
	});
}

void WhiteTeamFactory::addBishops()
{
	_pieces.insert(_pieces.end(), { new WhiteBishop(Position(0, 2), 11), new WhiteBishop(Position(0, 5), 14) });
}

void WhiteTeamFactory::addQueen()
{
	_pieces.push_back(new WhiteQueen(Position(0, 3), 12));
}

void WhiteTeamFactory::addKing()
{
	_pieces.push_back(new WhiteKing(Position(0, 4), 13));
}

void WhiteTeamFactory::addRooks()
{
	_pieces.insert(_pieces.end(), { new WhiteRook(Position(0, 0), 9), new WhiteRook(Position(0, 7), 16) });
}

void WhiteTeamFactory::addKnights()
{
	_pieces.insert(_pieces.end(), { new WhiteKnight(Position(0, 1), 10), new WhiteKnight(Position(0, 6), 15) });
}

Piece* WhiteTeamFactory::getNewBishop(const Position& pos)
{
	Piece* bishop = new WhiteBishop(pos, this->_over);
	PieceManager::GetPieceMap()[this->_over++] = bishop;
	return bishop;
}

Piece* WhiteTeamFactory::getNewKnight(const Position& pos)
{
	Piece* knight = new WhiteKnight(pos, this->_over);
	PieceManager::GetPieceMap()[this->_over++] = knight;
	return knight;
}

Piece* WhiteTeamFactory::getNewRook(const Position& pos)
{
	Piece* rook = new WhiteRook(pos, this->_over);
	PieceManager::GetPieceMap()[this->_over++] = rook;
	return rook;
}

Piece* WhiteTeamFactory::getNewQueen(const Position& pos)
{
	Piece* queen = new WhiteQueen(pos, this->_over);
	PieceManager::GetPieceMap()[this->_over++] = queen;
	return queen;
}