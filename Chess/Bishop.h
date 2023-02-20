#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(GameDataRef, const Position&, int);
	void Update(Table);
};

