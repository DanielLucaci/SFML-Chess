#include "CastleMove.h"
#include "PieceManager.h"

void CastleMove::makeMove(Table table)
{
	Move::makeMove(table);
	PieceMap pieceMap = PieceManager::GetPieceMap();
	Piece* rook = pieceMap.at(this->_rook.id);
	Piece* lockedPiece = rook->GetLockedPiece();
	if (lockedPiece != nullptr) {
		lockedPiece->SetLockingPiece(nullptr);
		rook->SetLockedPiece(nullptr);
	}
	Utils::SetTablePosition(table, this->_rook.previous);
	Utils::SetTablePosition(table, this->_rook.actual, this->_rook.id);
	rook->SetPosition(this->_rook.actual);
	rook->SetMoved(true);
}

void CastleMove::undoMove(Table table)
{
	Move::undoMove(table);
	PieceMap& pieceMap = PieceManager::GetPieceMap();
	Piece* rook = pieceMap.at(this->_rook.id);
	Utils::SetTablePosition(table, this->_rook.actual, 0);
	Utils::SetTablePosition(table, this->_rook.previous, this->_rook.id);
	rook->SetPosition(this->_rook.previous);
	rook->SetMoved(false);
}
