#pragma once
#include "King.h"
#include "DEFINITIONS.h"
#include <iostream>

class BlackKing : public King
{
public:
	BlackKing(const Position& position, int id);
};