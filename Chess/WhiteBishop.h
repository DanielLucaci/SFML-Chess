#pragma once
#include "Bishop.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhiteBishop : public Bishop
{
public:
	WhiteBishop(const Position& position, int id);
};
