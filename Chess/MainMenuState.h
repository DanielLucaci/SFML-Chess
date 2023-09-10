#pragma once
#include "State.h"
#include "Game.h"
#include "PlayBox.h"

class MainMenuState : public State
{
public:
	MainMenuState();
	~MainMenuState() = default;
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

	sf::Sprite& getPlayButtonSprite();
private:
	sf::Sprite _background, _playButton;
	sf::Clock _clock;
};

