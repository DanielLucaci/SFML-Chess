#pragma once
#include "King.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhiteKing : public King
{
public:
	WhiteKing(GameDataRef data, const Position& position, int id) : King(data, position, id)
	{
		this->texture = sf::Sprite(_data->assets.GetTexture("White King"));
		this->UpdatePiecePosition();
	}
};