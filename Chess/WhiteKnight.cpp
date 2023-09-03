#include "WhiteKnight.h"
#include "AssetManager.h"

WhiteKnight::WhiteKnight(const Position& position, int id) : Knight(position, id)
{
	switch (this->id) {
	case 10: // Left Side
		this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(2, 0))));
		this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(2, 2))));
		break;
	case 15: //Right Side
		this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(2, 5))));
		this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(2, 7))));
		break;
	default:
		break;
	}

	this->texture = sf::Sprite(assetManager->GetTexture("White Knight"));
	this->UpdatePiecePosition();
}