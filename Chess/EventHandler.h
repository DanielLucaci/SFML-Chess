#pragma once
#include "State.h"
#include <SFML/Window.hpp>
#include <map>

typedef void (*HandlerFunction)();

class EventHandler
{
public:
	EventHandler(State* state);
	~EventHandler() = default;
	void handleCloseEvent();
	void handleInput();
	virtual void handleMouseButtonPressed() = 0;
protected:
	State* _state;
	std::map<sf::Event::EventType, HandlerFunction> _eventMap;
};

