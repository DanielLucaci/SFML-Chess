#include "BlackQueen.h"
#include "GameData.h"

BlackQueen::BlackQueen(const Position& position, int id) : Queen(position, id)
{
	this->texture = sf::Sprite(data->assets->GetTexture("Black Queen"));
	this->UpdatePiecePosition();
}