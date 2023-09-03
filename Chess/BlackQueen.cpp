#include "BlackQueen.h"
#include "AssetManager.h"

BlackQueen::BlackQueen(const Position& position, int id) : Queen(position, id)
{
	this->texture = sf::Sprite(assetManager->GetTexture("Black Queen"));
	this->UpdatePiecePosition();
}