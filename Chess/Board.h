#pragma once
#include "WhiteTeam.h"
#include "BlackTeam.h"
#include <map>

class Board
{
public:
	Board(Team*, Team*);
	Board(const Board&);

	~Board();

	const PieceMap& GetPieceMap() const;
	int GetPieceIdAt(const Position&) const;
	Piece* operator[](int pos) const;
	Table& GetTable();

	void MovePiece(Move*);
private: 
	inline void initTable();
	inline void initPieces();
	Team* whiteTeam;
	Team* blackTeam;
	Table table;
	PieceMap pieceMap;
	int overWhite, overBlack;
};



