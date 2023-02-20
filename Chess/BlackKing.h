#pragma once
#include "King.h"
#include "DEFINITIONS.h"
#include <iostream>

class BlackKing : public King
{
public:
	BlackKing(GameDataRef data, const Position& position, int id) : King(data, position, id)
	{
		this->texture = sf::Sprite(_data->assets.GetTexture("Black King"));
		this->UpdatePiecePosition();
	}
};