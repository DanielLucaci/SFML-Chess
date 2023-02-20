#pragma once
#include "Move.h"

class CaptureMove : public Move {
public:
	CaptureMove(PieceDef piece, int capturedPiece): Move(piece),  _capturedPiece(capturedPiece) 
	{
		this->type = MoveType::CAPTURE;
	}

	bool operator==(const CaptureMove& other) const 
	{
		return this->m_piece == other.m_piece && this->_capturedPiece == other._capturedPiece;
	}

	void makeMove(Table table) override;
	void undoMove(Table table) override;
private: 
	int _capturedPiece;
};