#pragma once
#include "Piece.h"
#include "DEFINITIONS.h"
#include "Utils.h"
#include "CastleMove.h"
#include "EnPassant.h"
#include "Move.h"

typedef std::vector<Piece*> Pieces;

class Team
{
public:
	Team(GameDataRef, Table);
	Team(const Team&);
	~Team();

	Team& operator=(const Team&);

	virtual bool ProcessIllegalMoves(Team*) = 0;
	virtual void init() = 0;
	virtual void checkQueenSideCastling(Team*) = 0;
	virtual void checkKingSideCastling(Team*) = 0;
	virtual void checkForEnPassant(int) = 0;


	void Update(Team*);
	virtual void UpdateKing() = 0;
	
	void AddValidPlace(const Position&);
	virtual void AddNewBishop(const Position&) = 0;
	virtual void AddNewKnight(const Position&) = 0;
	virtual void AddNewRook(const Position&) = 0;
	virtual void AddNewQueen(const Position&) = 0;

	const Pieces& getGivingCheckPiece() const;
	const Pieces& getPieces() const;
	const bool& isCheck() const;
	const bool& isDoubleCheck() const;
	Move* GetLastMove();	
	void AddMove(Move*);

	int GetOver() const ;
	void IncrementOver();

	const Moves& GetMoves() const;

	const Places& GetValidPlaces() const;
	
	void Clear();
	bool hasValidMoves() const;

	void displayValidPlaces() const; 

protected:
	Pieces pieces, givingCheck;
	bool check, doubleCheck;
	GameDataRef _data;
	Moves _moves;
	Places _validPlaces;
	Table _table;
	int over;
};
