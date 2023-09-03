#include "BlackBishop.h"
#include "AssetManager.h"

BlackBishop::BlackBishop(const Position& position, int id) : Bishop(position, id)
{
	this->texture = sf::Sprite(assetManager->GetTexture("Black Bishop"));
	this->UpdatePiecePosition();
}