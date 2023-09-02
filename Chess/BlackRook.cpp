#include "BlackRook.h"
#include "GameData.h"

BlackRook::BlackRook(const Position& position, int id) : Rook(position, id)
{
	this->texture = sf::Sprite(data->assets->GetTexture("Black Rook"));
	this->UpdatePiecePosition();
}