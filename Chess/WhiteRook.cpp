#include "WhiteRook.h"
#include "AssetManager.h"

WhiteRook::WhiteRook(const Position& position, int id) : Rook(position, id)
{
	this->texture = sf::Sprite(assetManager->GetTexture("White Rook"));
	this->UpdatePiecePosition();
}