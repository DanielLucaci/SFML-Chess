#pragma once
#include "TeamFactory.h"

class BlackTeamFactory: public TeamFactory
{
public:
	BlackTeamFactory();

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

