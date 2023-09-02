#pragma once
#include "DEFINITIONS.h"
#include <iostream>


enum class MoveType {
	NORMAL,
	CAPTURE,
	CASTLE,
	ENPASSANT,
	TRANSFORM
};

struct PieceDef {
	int id;
	Position previous, actual;
	PieceDef(int id, Position previous, Position actual) {
		this->id = id;
		this->previous = previous;
		this->actual = actual;
	}

	PieceDef(const PieceDef& other) {
		this->id = other.id;
		this->previous = other.previous;
		this->actual = other.actual;
	}

	bool operator==(const PieceDef& other) const{
		return this->id == other.id &&
		this->previous == other.previous &&
		this->actual == other.actual;
	}
};

class Move {
public:
	Move() = delete;

	Move(PieceDef piece): m_piece(piece) 
	{
		this->type = MoveType::NORMAL;
		this->_firstMove = false;
	}

	int GetPieceId() {
		return m_piece.id;
	}

	const MoveType& GetType() const {
		return this->type;
	}

	bool operator==(const Move& other) const {
		return this->GetActualPosition() == other.GetActualPosition() && 
			   this->GetPreviousPosition() == other.GetPreviousPosition() &&
		       this->m_piece == other.m_piece;
	}

	const Position& GetActualPosition() const {
		return this->m_piece.actual;
	}

	const Position& GetPreviousPosition() const {
		return this->m_piece.previous;
	}

	friend std::ostream& operator<<(std::ostream& out, const Move& move) {
		out << "Id " << move.m_piece.id << "\n";
		out << "Previous position: (" << move.m_piece.previous.x << ", " << move.m_piece.previous.y << ")\n";
		out << "Actual position: (" << move.m_piece.actual.x << ", " << move.m_piece.actual.y << ")\n";
		return out;
	}

	virtual void makeMove(Table table);
	virtual void undoMove(Table table);

protected:
	PieceDef m_piece;
	MoveType type;
	bool _firstMove;
};

