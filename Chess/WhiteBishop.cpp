#include "WhiteBishop.h"
#include "GameData.h"

WhiteBishop::WhiteBishop(const Position& position, int id) : Bishop(position, id) {
	this->texture = sf::Sprite(data->assets->GetTexture("White Bishop"));
	this->UpdatePiecePosition();
}