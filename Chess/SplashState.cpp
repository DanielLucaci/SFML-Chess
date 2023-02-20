#include "SplashState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include <iostream>

SplashState::SplashState(GameDataRef data): _data(data) {
	this->Init();
}

void SplashState::Init() {
	_data->assets.LoadTexture("Splash State Background", SPLASH_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
}

void SplashState::HandleInput() {
	sf::Event event;
	while (_data->window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				_data->window->close();
				break;
			case sf::Event::MouseButtonPressed:
				_data->machine.AddState(StateRef(new MainMenuState(this->_data)));
				break;
			default:
				break;
		}
	}
}

void SplashState::Update(float dt) {
	if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
		_data->machine.AddState(StateRef(new MainMenuState(this->_data)));
	}
}

void SplashState::Draw(float dt) {
	_data->window->clear();
	_data->window->draw(_background);
	_data->window->display();
}