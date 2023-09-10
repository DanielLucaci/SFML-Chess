#include "EventHandler.h"
#include "WindowManager.h"
#include <utility>

EventHandler::EventHandler()
{
	this->_eventMap.emplace(sf::Event::Closed, std::bind(&EventHandler::handleCloseEvent, this));
}

void EventHandler::handleCloseEvent()
{
	window->close();
}

void EventHandler::handleInput() 
{
	while (window->pollEvent(event))
	{
		if(this->_eventMap.count(event.type))
			this->_eventMap[event.type]();
	}
}
