#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"

class InputManager
{
public:
	InputManager() = default;
	~InputManager() = default;

	bool isSpriteClicked(const sf::Sprite&, sf::Mouse::Button, WindowRef);
	bool isSpriteHovered(const sf::Sprite&, WindowRef);
	sf::Vector2i GetMousePosition(WindowRef);
};

