#pragma once
#include "Rook.h"
#include "DEFINITIONS.h"
#include <iostream>

class WhiteRook : public Rook
{
public:
	WhiteRook(const Position& position, int id);
};