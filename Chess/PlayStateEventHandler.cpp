#include "PlayStateEventHandler.h"
#include "WindowManager.h"
#include <SFML/Window.hpp>

PlayStateEventHandler::PlayStateEventHandler(PlayState* state) : EventHandler(), _lockClick(state->GetLockClick())
{
	update = std::bind(&PlayState::Update, *state, std::placeholders::_1);
	_eventMap.emplace(sf::Event::MouseButtonReleased, std::bind(&PlayStateEventHandler::handleMouseButtonReleased, this));
	_eventMap.emplace(sf::Event::MouseButtonPressed, std::bind(&PlayStateEventHandler::handleMouseButtonReleased, this));
}

void PlayStateEventHandler::handleMouseButtonPressed()
{
	if (event.mouseButton.button == sf::Mouse::Left && !this->_lockClick) {
		this->update(0.f);
		this->_lockClick = true;
	}
}

void PlayStateEventHandler::handleMouseButtonReleased()
{
	if (event.mouseButton.button == sf::Mouse::Left && this->_lockClick)
		this->_lockClick = false;
}