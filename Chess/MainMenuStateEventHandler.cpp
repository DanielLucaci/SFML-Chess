#include "MainMenuStateEventHandler.h"
#include "InputManager.h"
#include "StateManager.h"
#include "AssetManager.h"
#include "PlayState.h"

MainMenuStateEventHandler::MainMenuStateEventHandler(MainMenuState* state): _playButton(state->getPlayButtonSprite())
{
	this->_eventMap.emplace(sf::Event::MouseButtonPressed, std::bind(&MainMenuStateEventHandler::handleMouseButtonPressed, this));
	this->_eventMap.emplace(sf::Event::MouseMoved, std::bind(&MainMenuStateEventHandler::handleMouseMoved, this));
}

void MainMenuStateEventHandler::handleMouseButtonPressed()
{
	if (inputManager->isSpriteClicked(_playButton, sf::Mouse::Left)) {
		stateManager->AddState(StateRef(new PlayState()));
	}
}

void MainMenuStateEventHandler::handleMouseMoved() 
{
	if (inputManager->isSpriteHovered(_playButton))
		_playButton.setTexture(assetManager->GetTexture("Play Button Hover"));
	else
		_playButton.setTexture(assetManager->GetTexture("Play Button"));
}