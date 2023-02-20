#pragma once
#include "Move.h"

class EnPassant: public Move
{
public:
	EnPassant(PieceDef pawn, int capturedPawnId, Position capturedPawnPosition) : Move(pawn) {
		this->_capturedPawnId = capturedPawnId;
		this->_capturedPawnPosition = capturedPawnPosition;
	}
	
	void makeMove(Table) override;
	void undoMove(Table) override;
private:
	int _capturedPawnId;
	Position _capturedPawnPosition;
};

