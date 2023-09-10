#include "MainMenuState.h"
#include "PlayState.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "StateManager.h"
#include "WindowManager.h"
#include "MainMenuStateEventHandler.h"

// TODO: Inject window

MainMenuState::MainMenuState()
{
	this->Init();
	this->eventHandler = new MainMenuStateEventHandler(this);
}

void MainMenuState::Init() 
{
	_background.setTexture(assetManager->GetTexture("Main Menu Background"));
	_playButton.setTexture(assetManager->GetTexture("Play Button"));
	_playButton.setPosition(
		(int)(SCREEN_WIDTH / 2.f - _playButton.getLocalBounds().width / 2.f), 
		(int)(SCREEN_HEIGHT / 2.f - _playButton.getLocalBounds().height / 2.f)
	);
}

void MainMenuState::HandleInput() {
	eventHandler->handleInput();
}

void MainMenuState::Update(float dt) {
	
}

void MainMenuState::Draw(float dt) {
	window->clear();
	window->draw(_background);
	window->draw(_playButton);
	window->display();
}

sf::Sprite& MainMenuState::getPlayButtonSprite()
{
	return this->_playButton;
}
