#include "InputManager.h"
#include "WindowManager.h"

InputManager* InputManager::_instance = nullptr;

InputManager* const inputManager = InputManager::getInputManager();

InputManager::~InputManager() 
{
	if (_instance != nullptr) 
		delete(_instance);
}

InputManager* InputManager::getInputManager()
{
	if (_instance == nullptr) {
		_instance = new InputManager();
	}
	return _instance;
}

bool InputManager::isSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button) 
{
	if (sf::Mouse::isButtonPressed(button)) 
	{
		sf::IntRect tempRect((int)object.getPosition().x, (int)object.getPosition().y, (int)object.getGlobalBounds().width, (int)object.getGlobalBounds().height);
		if (tempRect.contains(GetMousePosition())) 
			return true;
	}
	return false;
}

bool InputManager::isSpriteHovered(const sf::Sprite& object) {
	sf::IntRect tempRect((int)object.getPosition().x, (int)object.getPosition().y, (int)object.getGlobalBounds().width, (int)object.getGlobalBounds().height);
	if (tempRect.contains(GetMousePosition())) 
		return true;
	return false;
}

sf::Vector2i InputManager::GetMousePosition() {
	return sf::Mouse::getPosition(*window);
}