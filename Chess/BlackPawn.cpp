#include "BlackPawn.h"
#include "AssetManager.h"

BlackPawn::BlackPawn(const Position& position, int id) : Pawn(position, id)
{
	this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(position.x - 1, position.y))));
	this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(position.x - 2, position.y))));

	this->texture = sf::Sprite(assetManager->GetTexture("Black Pawn"));
	this->UpdatePiecePosition();
}