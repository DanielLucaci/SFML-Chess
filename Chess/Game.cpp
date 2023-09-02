#include "Game.h"
#include "SplashState.h"
#include "GameData.h"

Game::Game(int width, int height, const std::string& title) {
	data->window->create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	data->window->setFramerateLimit(60);
	data->window->setKeyRepeatEnabled(false);


	// Load Icon
	data->assets->LoadIcon("Window Icon", ICON_FILEPATH);
	sf::Image& icon = data->assets->GetIcon("Window Icon");
	data->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	
	data->machine->AddState(StateRef(new SplashState()));
	this->Run();
}

void Game::Run() {
	float newTime, frameTime;
	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.f;

	while (data->window->isOpen()) {
		data->machine->ProcessStateChanges();
		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;
		currentTime = newTime;

		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		accumulator += frameTime;

		while (accumulator >= dt) {
			data->machine->GetActiveState()->HandleInput();
			data->machine->GetActiveState()->Update(dt);
			accumulator -= dt;
		}

		data->machine->GetActiveState()->Draw(dt);
	}
}