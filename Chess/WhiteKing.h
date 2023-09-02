#pragma once
#include "King.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhiteKing : public King
{
public:
	WhiteKing(const Position& position, int id);
};