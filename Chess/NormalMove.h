#pragma once
#include "Move.h"

class NormalMove : public Move {
public:
	NormalMove(PieceDef piece) : Move(piece) {
		this->type = MoveType::NORMAL;
	}

	bool operator==(const NormalMove& other) const{
		return this->m_piece == other.m_piece && 
			   this->GetActualPosition() == other.GetActualPosition() && 
			   this->GetPreviousPosition() == other.GetPreviousPosition() &&
			   this->GetType() == other.GetType();
	}

	void makeMove(Table) override;
	void undoMove(Table) override;
};