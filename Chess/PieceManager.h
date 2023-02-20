#pragma once
#include "Piece.h"
#include "Team.h"
#include <map>

typedef std::map<int, Piece*> PieceMap;

class PieceManager
{
public:
	PieceManager(GameDataRef);
	PieceManager& LoadPieces(Team*);
	void AddPiece(Piece*);
	static PieceMap& GetPieceMap();
	Piece* operator[](int id);
private:
	static PieceMap _pieces;
};

