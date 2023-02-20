#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(GameDataRef, const Position&, int);
	void Update(Table);
};