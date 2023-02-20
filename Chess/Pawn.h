#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(GameDataRef, const Position&, int);
	void Update(Table);
};
