#pragma once
#include "Team.h"
#include "WhitePawn.h"
#include "WhiteKnight.h"
#include "WhiteBishop.h"
#include "WhiteRook.h"
#include "WhiteKing.h"
#include "WhiteQueen.h"

class WhiteTeam : public Team {
public:
	WhiteTeam(GameDataRef data, Table table);

	WhiteTeam(const WhiteTeam& other);

	void init();

   void checkKingSideCastling(Team*);

   void checkQueenSideCastling(Team*);

   void checkForEnPassant(int);

   bool ProcessIllegalMoves(Team*);

   void UpdateKing();

   void AddNewBishop(const Position&);
   
   void AddNewKnight(const Position&);

   void AddNewRook(const Position&);

   void AddNewQueen(const Position&);
};