#include "BlackBishop.h"
#include "GameData.h"

BlackBishop::BlackBishop(const Position& position, int id) : Bishop(position, id)
{
	this->texture = sf::Sprite(data->assets->GetTexture("Black Bishop"));
	this->UpdatePiecePosition();
}