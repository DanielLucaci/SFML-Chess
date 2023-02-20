#include "EnPassant.h"
#include "PieceManager.h"

void EnPassant::makeMove(Table table)
{
	Move::makeMove(table);
	PieceMap pieceMap = PieceManager::GetPieceMap();
	Piece* pawn = pieceMap.at(this->_capturedPawnId);
	Utils::SetTablePosition(table, _capturedPawnPosition);
	pawn->SetCaptured(true);
}

void EnPassant::undoMove(Table table)
{
	Move::undoMove(table);
	PieceMap& pieceMap = PieceManager::GetPieceMap();
	Piece* capturedPawn = pieceMap.at(_capturedPawnId);
	Utils::SetTablePosition(table, this->_capturedPawnPosition, this->_capturedPawnId);
	capturedPawn->SetCaptured(false);
}
