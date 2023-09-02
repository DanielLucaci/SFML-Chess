#pragma once
#include "Queen.h"
#include "DEFINITIONS.h"
#include <iostream>

class BlackQueen : public Queen
{
public:
	BlackQueen(const Position& position, int id);
};