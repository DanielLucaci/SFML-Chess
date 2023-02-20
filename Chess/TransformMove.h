#pragma once
#include "Move.h"

enum class TransformedPieceType {
	NOPIECE,
	ROOK,
	KNIGHT,
	QUEEN,
	BISHOP
};

class TransformMove : public Move {
public:
	TransformMove(PieceDef piece) : Move(piece), pieceType(TransformedPieceType::QUEEN)
	{
		this->type = MoveType::TRANSFORM;
	}

	bool operator==(const TransformMove& other) const {
		return this->m_piece == other.m_piece &&
			   this->pieceType == other.pieceType;
	}

	TransformedPieceType GetPieceType() const {
		return this->pieceType;
	}

	void SetPieceType(TransformedPieceType);

	void makeMove(Table) override;

private:
	TransformedPieceType pieceType;
};