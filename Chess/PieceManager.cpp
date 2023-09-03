#include "PieceManager.h"

PieceMap PieceManager::_pieces = PieceMap();

PieceManager::PieceManager() {}

PieceManager& PieceManager::LoadPieces(Team* team)
{
	for(Piece* p: team->getPieces())
		PieceManager::_pieces[p->GetId()] = p;
	return *this;
}

void PieceManager::AddPiece(Piece* p)
{
	PieceManager::_pieces[p->GetId()] = p;
}

PieceMap& PieceManager::GetPieceMap()
{
	// TODO: insert return statement here
	return PieceManager::_pieces;
}

Piece* PieceManager::operator[](int id)
{
    return PieceManager::_pieces.at(id);
}

