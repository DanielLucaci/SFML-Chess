#include "BlackKnight.h"
#include "AssetManager.h"

BlackKnight::BlackKnight(const Position& position, int id) : Knight(position, id)
{
	switch (this->id) {
	case 26: // Left Side
		this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(5, 0))));
		this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(5, 2))));
		break;
	case 31: //Right Side
		this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(5, 5))));
		this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(5, 7))));
		break;
	default:
		break;
	}
	this->texture = sf::Sprite(assetManager->GetTexture("Black Knight"));
	this->UpdatePiecePosition();
}