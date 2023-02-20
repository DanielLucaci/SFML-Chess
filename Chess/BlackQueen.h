#pragma once
#include "Queen.h"
#include "DEFINITIONS.h"
#include <iostream>

class BlackQueen : public Queen
{
public:
	BlackQueen(GameDataRef data, const Position& position, int id): Queen(data, position, id)
	{
		this->texture = sf::Sprite(_data->assets.GetTexture("Black Queen"));
		this->UpdatePiecePosition();
	}
};