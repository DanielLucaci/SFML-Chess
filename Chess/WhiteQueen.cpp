#include "GameData.h"
#include "WhiteQueen.h"

WhiteQueen::WhiteQueen(const Position& position, int id) : Queen(position, id)
{
	this->texture = sf::Sprite(data->assets->GetTexture("White Queen"));
	this->UpdatePiecePosition();
}