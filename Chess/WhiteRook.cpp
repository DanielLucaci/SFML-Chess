#include "GameData.h"
#include "WhiteRook.h"

WhiteRook::WhiteRook(const Position& position, int id) : Rook(position, id)
{
	this->texture = sf::Sprite(data->assets->GetTexture("White Rook"));
	this->UpdatePiecePosition();
}