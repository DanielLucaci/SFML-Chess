#include "Game.h"
#include "SplashState.h"
#include "AssetManager.h"
#include "StateManager.h"
#include "WindowManager.h"

// TODO: Inject window

Game::Game(int width, int height, const std::string& title) 
{
	window->create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
	window->setKeyRepeatEnabled(false);

	// Load Icon
	assetManager->LoadIcon("Window Icon", ICON_FILEPATH);
	sf::Image& icon = assetManager->GetIcon("Window Icon");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	stateManager->AddState(StateRef(new SplashState()));
	
	this->Run();
}

void Game::Run() {
	float newTime, frameTime;
	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.f;

	while (window->isOpen()) {
		stateManager->ProcessStateChanges();
		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;
		currentTime = newTime;

		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		accumulator += frameTime;

		while (accumulator >= dt) {
			stateManager->GetActiveState()->HandleInput();
			stateManager->GetActiveState()->Update(dt);
			accumulator -= dt;
		}

		stateManager->GetActiveState()->Draw(dt);
	}
}