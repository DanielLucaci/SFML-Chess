#include "WhiteKing.h"
#include "GameData.h"

WhiteKing::WhiteKing(const Position& position, int id) : King(position, id)
{
	this->texture = sf::Sprite(data->assets->GetTexture("White King"));
	this->UpdatePiecePosition();
}