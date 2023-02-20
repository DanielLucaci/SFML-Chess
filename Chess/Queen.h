#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(GameDataRef, const Position&, int);
	void Update(Table);
};

