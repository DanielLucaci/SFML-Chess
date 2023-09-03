#include "BlackRook.h"
#include "AssetManager.h"

BlackRook::BlackRook(const Position& position, int id) : Rook(position, id)
{
	this->texture = sf::Sprite(assetManager->GetTexture("Black Rook"));
	this->UpdatePiecePosition();
}