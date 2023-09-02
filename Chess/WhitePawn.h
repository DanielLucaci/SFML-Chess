#pragma once
#include "Pawn.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhitePawn : public Pawn {
public:
	WhitePawn(const Position& position, int id);
};