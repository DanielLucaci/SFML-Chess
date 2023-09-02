#pragma once
#include "Piece.h"

class Knight: public Piece
{
public:
	Knight(const Position&, int);
	void Update(Table);
};
