#pragma once
#include "TeamFactory.h"

class WhiteTeamFactory: public TeamFactory
{
public:
	WhiteTeamFactory();

	Piece* getNewRook(const Position&);
	Piece* getNewKnight(const Position&);
	Piece* getNewBishop(const Position&);
	Piece* getNewQueen(const Position&);
protected:
	void addPawns();
	void addBishops();
	void addQueen();
	void addKing();
	void addRooks();
	void addKnights();
};

