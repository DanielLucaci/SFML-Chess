#pragma once
#include "Pawn.h"
#include "DEFINITIONS.h"
#include <iostream>

class BlackPawn : public Pawn {
public:
	BlackPawn(const Position& position, int id);
};