#include "TransformMove.h"
#include "PieceManager.h"
#include "TeamManager.h"

void TransformMove::makeMove(Table table)
{
	PieceMap pieceMap = PieceManager::GetPieceMap();

	// Update captured Piece
	Piece* p = pieceMap.at(Utils::getPieceAt(m_piece.actual, table));
	if (p != nullptr) {
		p->SetCaptured(true);
		Piece* lockedPiece = p->GetLockedPiece();
		if (lockedPiece != nullptr) {
			lockedPiece->SetLockingPiece(nullptr);
			p->SetLockedPiece(nullptr);
		}
	}

	// Update table
	Utils::SetTablePosition(table, m_piece.previous);

	// Update Id of the new piece
	int id = m_piece.id;
	Team* currentTeam = TeamManager::GetTeam(id);
	currentTeam->AddMove(this);
	pieceMap.at(id)->SetCaptured(true);
	switch (this->pieceType) {
		case TransformedPieceType::BISHOP:
			currentTeam->AddNewBishop(m_piece.actual);
			break;
		case TransformedPieceType::KNIGHT:
			currentTeam->AddNewKnight(m_piece.actual);
			break;
		case TransformedPieceType::ROOK:
			currentTeam->AddNewRook(m_piece.actual);
			break;
		case TransformedPieceType::QUEEN:
			currentTeam->AddNewQueen(m_piece.actual);
			break;
		default:
			break;
	}
}


void TransformMove::SetPieceType(TransformedPieceType pieceType) {
	this->pieceType = pieceType;
}