#include "GameData.h"
#include "BlackKing.h"

BlackKing::BlackKing(const Position& position, int id) : King(position, id)
{
	this->texture = sf::Sprite(data->assets->GetTexture("Black King"));
	this->UpdatePiecePosition();
}