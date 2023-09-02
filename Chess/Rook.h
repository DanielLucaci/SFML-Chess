#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(const Position&, int);
	void Update(Table);
};