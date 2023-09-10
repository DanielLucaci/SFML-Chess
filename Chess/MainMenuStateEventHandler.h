#pragma once
#include "EventHandler.h"
#include "MainMenuState.h"
#include <SFML/Graphics.hpp>

class MainMenuStateEventHandler: public EventHandler
{
public:
	MainMenuStateEventHandler(MainMenuState* state);

	void handleMouseButtonPressed();
	void handleMouseMoved();
private:
	sf::Sprite& _playButton;
};

