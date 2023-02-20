#pragma once
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "UIManager.h"


struct GameData {
	AssetManager assets;
	StateMachine machine;
	WindowRef window = std::make_shared<sf::RenderWindow>();
	InputManager input;
	UIManager ui = UIManager(this->window);
};

typedef std::shared_ptr<GameData> GameDataRef;