#include "WhiteQueen.h"
#include "AssetManager.h"

WhiteQueen::WhiteQueen(const Position& position, int id) : Queen(position, id)
{
	this->texture = sf::Sprite(assetManager->GetTexture("White Queen"));
	this->UpdatePiecePosition();
}