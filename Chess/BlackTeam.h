#pragma once
#pragma once
#include "Team.h"
#include "BlackPawn.h"
#include "BlackKnight.h"
#include "BlackBishop.h"
#include "BlackRook.h"
#include "BlackKing.h"
#include "BlackQueen.h"


class BlackTeam : public Team {
public:
	BlackTeam(GameDataRef, Table);

	BlackTeam(const BlackTeam&);

	
	void init();

	bool ProcessIllegalMoves(Team*);

	void checkKingSideCastling(Team*);

	void checkQueenSideCastling(Team*);

	void checkForEnPassant(int);

	void UpdateKing();

	void AddNewBishop(const Position&);

	void AddNewKnight(const Position&);

	void AddNewRook(const Position&);

	void AddNewQueen(const Position&);
};