#pragma once
#include "Rook.h"
#include "DEFINITIONS.h"
#include <iostream>

class BlackRook : public Rook
{
public:
	BlackRook(GameDataRef data, const Position& position, int id): Rook(data, position, id)
	{
		this->texture = sf::Sprite(_data->assets.GetTexture("Black Rook"));
		this->UpdatePiecePosition();
	}
};