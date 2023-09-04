#include "PlayStateEventHandler.h"
#include "WindowManager.h"
#include <SFML/Window.hpp>

PlayStateEventHandler::PlayStateEventHandler(State* state) : EventHandler(state)
{
	_eventMap.emplace((sf::Event::MouseButtonReleased, handleMouseButtonReleased));
}

void PlayStateEventHandler::handleMouseButtonPressed()
{
}

void PlayStateEventHandler::handleMouseButtonReleased()
{
}
