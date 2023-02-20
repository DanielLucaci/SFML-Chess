#pragma once
#include "Bishop.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhiteBishop : public Bishop
{
public:
	WhiteBishop(GameDataRef data, const Position& position, int id): Bishop(data, position, id)
	{
		this->texture = sf::Sprite(_data->assets.GetTexture("White Bishop"));
		this->UpdatePiecePosition();
	}
};
