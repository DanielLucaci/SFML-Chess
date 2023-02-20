#pragma once
#include "Queen.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhiteQueen : public Queen
{
public:
	WhiteQueen(GameDataRef data, const Position& position, int id) : Queen(data, position, id)
	{
		this->texture = sf::Sprite(_data->assets.GetTexture("White Queen"));
		this->UpdatePiecePosition();
	}
};

