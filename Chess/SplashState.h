#pragma once
#include "State.h"
#include "Game.h"
#include <thread>

class SplashState: public State
{
public: 
	SplashState();

	void LoadAssets();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
private:
	bool _isLoadCompleted;
	sf::Clock _clock;
	sf::Sprite _background;
	std::thread _loadThread;
};

