#pragma once
#include "Piece.h"

class Knight: public Piece
{
public:
	Knight(GameDataRef, const Position&, int);
	void Update(Table);
};
