#include "InputManager.h"

bool InputManager::isSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, WindowRef window) {
	if (sf::Mouse::isButtonPressed(button)) {
		sf::IntRect tempRect((int)object.getPosition().x, (int)object.getPosition().y, (int)object.getGlobalBounds().width, (int)object.getGlobalBounds().height);
		if (tempRect.contains(GetMousePosition(window))) {
			return true;
		}
	}
	return false;
}

bool InputManager::isSpriteHovered(const sf::Sprite& object, WindowRef window) {
	sf::IntRect tempRect((int)object.getPosition().x, (int)object.getPosition().y, (int)object.getGlobalBounds().width, (int)object.getGlobalBounds().height);
	if (tempRect.contains(GetMousePosition(window))) 
		return true;
	return false;
}

sf::Vector2i InputManager::GetMousePosition(WindowRef window) {
	return sf::Mouse::getPosition(*window);
}