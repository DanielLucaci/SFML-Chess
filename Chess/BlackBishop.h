#pragma once
#include "Bishop.h"
#include "DEFINITIONS.h"
#include <iostream>

class BlackBishop : public Bishop
{
  public:
	  BlackBishop(const Position& position, int id);
};
