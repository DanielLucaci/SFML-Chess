#pragma once
#include "Queen.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhiteQueen : public Queen
{
public:
	WhiteQueen(const Position& position, int id);
};

