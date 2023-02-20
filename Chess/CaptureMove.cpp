#include "CaptureMove.h"
#include "PieceManager.h"

void CaptureMove::makeMove(Table table)
{
	Move::makeMove(table);
	PieceMap pieceMap = PieceManager::GetPieceMap();
	Piece* p = pieceMap.at(this->_capturedPiece);
	Piece* lockedPiece = p->GetLockedPiece();
	if (lockedPiece != nullptr) {
		lockedPiece->SetLockingPiece(nullptr);
		p->SetLockedPiece(nullptr);
	}
	p->SetCaptured(true);
}

void CaptureMove::undoMove(Table table)
{
	Move::undoMove(table);
	PieceMap& pieceMap = PieceManager::GetPieceMap();
	Piece* capturedPiece = pieceMap.at(this->_capturedPiece);
	Utils::SetTablePosition(table, this->m_piece.actual, this->_capturedPiece);
	capturedPiece->SetCaptured(false);
}
