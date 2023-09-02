#pragma once
#include "State.h"
#include "Game.h"

class SplashState: public State
{
public: 
	SplashState();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
private:
	sf::Clock _clock;
	sf::Sprite _background;
};

