#pragma once
#include "Piece.h"
#include <vector>

class TeamFactory
{
public:
	std::vector<Piece*> createTeam();

	TeamFactory(int over);

	virtual Piece* getNewRook(const Position&) = 0;
	virtual Piece* getNewKnight(const Position&) = 0;
	virtual Piece* getNewBishop(const Position&) = 0;
	virtual Piece* getNewQueen(const Position&) = 0;
protected:
	virtual void addPawns() = 0;
	virtual void addBishops() = 0;
	virtual void addQueen() = 0;
	virtual void addKing() = 0;
	virtual void addRooks() = 0;
	virtual void addKnights() = 0;

	std::vector<Piece*> _pieces;

	int _over;
};

