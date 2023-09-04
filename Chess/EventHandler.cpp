#include "EventHandler.h"
#include "WindowManager.h"

EventHandler::EventHandler(State* state)
{
	this->_state = state;
	this->_eventMap.emplace((sf::Event::Closed, handleCloseEvent));
	this->_eventMap.emplace((sf::Event::MouseButtonPressed, handleMouseButtonPressed));
}

void EventHandler::handleCloseEvent()
{
	window->close();
}

void EventHandler::handleInput() 
{
	sf::Event event;
	while (window->pollEvent(event))
		this->_eventMap[event.type]();
}
