#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(const Position&, int);
	void Update(Table);
};

