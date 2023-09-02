#include "PieceManager.h"
#include "GameData.h"

PieceMap PieceManager::_pieces = PieceMap();

PieceManager::PieceManager()
{
	data->assets->LoadTexture("Black Pawn", BLACK_PAWN_FILEPATH);
	data->assets->LoadTexture("Black Bishop", BLACK_BISHOP_FILEPATH);
	data->assets->LoadTexture("Black Rook", BLACK_ROOK_FILEPATH);
	data->assets->LoadTexture("Black Knight", BLACK_KNIGHT_FILEPATH);
	data->assets->LoadTexture("Black Queen", BLACK_QUEEN_FILEPATH);
	data->assets->LoadTexture("Black King", BLACK_KING_FILEPATH);
	data->assets->LoadTexture("White Pawn", WHITE_PAWN_FILEPATH);
	data->assets->LoadTexture("White Bishop", WHITE_BISHOP_FILEPATH);
	data->assets->LoadTexture("White Rook", WHITE_ROOK_FILEPATH);
	data->assets->LoadTexture("White Knight", WHITE_KNIGHT_FILEPATH);
	data->assets->LoadTexture("White Queen", WHITE_QUEEN_FILEPATH);
	data->assets->LoadTexture("White King", WHITE_KING_FILEPATH);
	data->assets->LoadTexture("Table", PLAY_STATE_BACKGROUND_FILEPATH);
	data->assets->LoadFont("Times New Roman", TIMES_NEW_ROMAN_FONT_FILEPATH);
}

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

