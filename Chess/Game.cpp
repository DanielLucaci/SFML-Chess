#include "Game.h"
#include "SplashState.h"

Game::Game(int width, int height, const std::string& title) {
	_data->window->create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	_data->window->setFramerateLimit(60);
	_data->window->setKeyRepeatEnabled(false);


	// Load Icon
	_data->assets.LoadIcon("Window Icon", ICON_FILEPATH);
	sf::Image& icon = _data->assets.GetIcon("Window Icon");
	_data->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	
	_data->machine.AddState(StateRef(new SplashState(this->_data)));
	this->Run();
}

void Game::Run() {
	float newTime, frameTime;
	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.f;

	while (this->_data->window->isOpen()) {
		this->_data->machine.ProcessStateChanges();
		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;
		currentTime = newTime;

		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		accumulator += frameTime;

		while (accumulator >= dt) {
			this->_data->machine.GetActiveState()->HandleInput();
			this->_data->machine.GetActiveState()->Update(dt);
			accumulator -= dt;
		}

		this->_data->machine.GetActiveState()->Draw(dt);
	}
}