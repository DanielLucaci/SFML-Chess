#pragma once
#include "Board.h"
#include "GameData.h"
#include <memory>
#include <string>

class Game
{
public:
	Game(int, int, const std::string&);
private:
	const float dt = 1.f / 60.f;
	sf::Clock _clock;
	GameDataRef _data = std::make_shared<GameData>();
	void Run();
};

