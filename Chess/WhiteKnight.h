#pragma once
#include "Knight.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhiteKnight : public Knight
{
public:
	WhiteKnight(GameDataRef data, const Position& position, int id) : Knight(data, position, id)
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

		this->texture = sf::Sprite(_data->assets.GetTexture("White Knight"));
		this->UpdatePiecePosition();
	}
};
