#pragma once
#include "Board.h"
#include <memory>
#include <string>

class Game
{
public:
	Game(int, int, const std::string&);
private:
	const float dt = 1.f / 60.f;
	void Run();
};

