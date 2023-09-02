#pragma once
#include "Piece.h"

class King: public Piece
{
public:
	King(const Position&, int);
	void Update(Table);
	bool isValidKing(const Position&, Table, const Places&);
};

