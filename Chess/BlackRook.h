#pragma once
#include "Rook.h"
#include "DEFINITIONS.h"
#include <iostream>

class BlackRook : public Rook
{
public:
	BlackRook(const Position& position, int id);
};