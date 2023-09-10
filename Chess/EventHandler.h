#pragma once
#include "State.h"
#include <SFML/Window.hpp>
#include <map>
#include <functional>

typedef std::function<void(void)> HandlerFunction;

class EventHandler
{
public:
	EventHandler();
	~EventHandler() = default;
	void handleCloseEvent();
	void handleInput();
protected:
	std::map<sf::Event::EventType, HandlerFunction> _eventMap;
	sf::Event event;
};

