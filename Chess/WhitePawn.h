#pragma once
#include "Pawn.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhitePawn : public Pawn {
public:
	WhitePawn(GameDataRef data, const Position& position, int id) : Pawn(data, position, id)
	{
		this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(position.x + 1, position.y))));
		this->AddValidMove(new NormalMove(PieceDef(this->id, this->position, Position(position.x + 2, position.y))));
		this->texture = sf::Sprite(_data->assets.GetTexture("White Pawn"));
		this->UpdatePiecePosition();
	}
};