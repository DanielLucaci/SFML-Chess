#pragma once
#include "Bishop.h"
#include "DEFINITIONS.h"
#include <iostream>

class BlackBishop : public Bishop
{
public:
	BlackBishop(GameDataRef data, const Position& position, int id) : Bishop(data, position, id)
	{
		this->texture = sf::Sprite(_data->assets.GetTexture("Black Bishop"));
		this->UpdatePiecePosition();
	}
};
