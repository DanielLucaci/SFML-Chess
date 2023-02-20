#include "Move.h"
#include "PieceManager.h"

void Move::makeMove(Table table)
{
	PieceMap& pieceMap = PieceManager::GetPieceMap();
	Piece* p = pieceMap.at(this->m_piece.id);
	Piece* lockedPiece = p->GetLockedPiece();
	if (lockedPiece != nullptr) {
		lockedPiece->SetLockingPiece(nullptr);
		p->SetLockedPiece(nullptr);
	}
	Utils::SetTablePosition(table, this->m_piece.previous);
	Utils::SetTablePosition(table, this->m_piece.actual, p->GetId());
	p->SetPosition(this->m_piece.actual);
	if (p->GetMoved() == false) 
		this->_firstMove = true;
	p->SetMoved(true);
}

void Move::undoMove(Table table)
{
	PieceMap& pieceMap = PieceManager::GetPieceMap();
	Piece* p = pieceMap.at(this->m_piece.id);
	Utils::SetTablePosition(table, this->m_piece.actual);
	Utils::SetTablePosition(table, this->m_piece.previous, p->GetId());
	p->SetPosition(this->m_piece.previous);
	if (this->_firstMove == true) {
		this->_firstMove = false;
		p->SetMoved(false);
	}
}
