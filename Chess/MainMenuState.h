#pragma once
#include "State.h"
#include "Game.h"
#include "PlayBox.h"

class MainMenuState : public State
{
public:
	MainMenuState(GameDataRef _data);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
private:
	GameDataRef _data;
	sf::Sprite _background, _playButton;
	sf::Clock _clock;
};

