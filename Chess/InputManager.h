#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"

class InputManager
{
public:
	InputManager(const InputManager&) = delete;

	~InputManager();

	static InputManager* getInputManager();

	bool isSpriteClicked(const sf::Sprite&, sf::Mouse::Button);
	bool isSpriteHovered(const sf::Sprite&);
	sf::Vector2i GetMousePosition();
private:
	InputManager() = default;

	static InputManager* _instance;
};

extern InputManager* const inputManager;