#pragma once
#include "Move.h"

class CastleMove : public Move {
public:
	CastleMove(PieceDef king, PieceDef rook) : Move(king), _rook(rook) 
	{
		this->type = MoveType::CASTLE;
	}

	bool operator==(const CastleMove& other) const {
		return this->m_piece == other.m_piece && this->_rook == other._rook;
	}

	void makeMove(Table) override;
	void undoMove(Table) override;
private:
	PieceDef _rook;
};