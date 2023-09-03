#include "WhiteBishop.h"
#include "AssetManager.h"

WhiteBishop::WhiteBishop(const Position& position, int id) : Bishop(position, id) {
	this->texture = sf::Sprite(assetManager->GetTexture("White Bishop"));
	this->UpdatePiecePosition();
}