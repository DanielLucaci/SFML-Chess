#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(const Position&, int);
	void Update(Table);
};
