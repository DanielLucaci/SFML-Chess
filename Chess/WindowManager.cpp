#include "WindowManager.h"

WindowManager* WindowManager::_instance = nullptr;

sf::RenderWindow* const window = WindowManager::getInstance()->getWindow();

WindowManager::WindowManager() 
{
	this->_window = new sf::RenderWindow();
}

WindowManager::~WindowManager()
{
	if (_instance != nullptr)
		delete(_instance);
	delete(_window);
}

WindowManager* WindowManager::getInstance()
{
	if (_instance == nullptr)
		_instance = new WindowManager();
	return _instance;
}

sf::RenderWindow* WindowManager::getWindow() 
{
	return _window;
}