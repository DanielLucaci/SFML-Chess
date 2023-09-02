#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const Position&, int);
	void Update(Table);
};

