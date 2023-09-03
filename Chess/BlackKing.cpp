#include "BlackKing.h"
#include "AssetManager.h"

BlackKing::BlackKing(const Position& position, int id) : King(position, id)
{
	this->texture = sf::Sprite(assetManager->GetTexture("Black King"));
	this->UpdatePiecePosition();
}