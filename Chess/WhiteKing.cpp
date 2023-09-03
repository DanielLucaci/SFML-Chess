#include "WhiteKing.h"
#include "AssetManager.h"

WhiteKing::WhiteKing(const Position& position, int id) : King(position, id)
{
	this->texture = sf::Sprite(assetManager->GetTexture("White King"));
	this->UpdatePiecePosition();
}