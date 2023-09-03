#pragma once
#include "SFML/Graphics.hpp"

class WindowManager {
public:
	WindowManager(const WindowManager&) = delete;

	~WindowManager();

	static WindowManager* getInstance();

	sf::RenderWindow* getWindow();
private:
	WindowManager();

	static WindowManager* _instance;
	sf::RenderWindow* _window;
};

extern sf::RenderWindow* const window;