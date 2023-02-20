#pragma once
#include "Rook.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhiteRook : public Rook
{
public:
	WhiteRook(GameDataRef data, const Position& position, int id) : Rook(data, position, id)
	{
		this->texture = sf::Sprite(_data->assets.GetTexture("White Rook"));
		this->UpdatePiecePosition();
	}
};