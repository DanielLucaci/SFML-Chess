#include "SplashState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include <iostream>
#include "GameData.h"

SplashState::SplashState()
{
	this->Init();
}

void SplashState::Init() {
	data->assets->LoadTexture("Splash State Background", SPLASH_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(data->assets->GetTexture("Splash State Background"));
}

void SplashState::HandleInput() {
	sf::Event event;
	while (data->window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				data->window->close();
				break;
			case sf::Event::MouseButtonPressed:
				data->machine->AddState(StateRef(new MainMenuState()));
				break;
			default:
				break;
		}
	}
}

void SplashState::Update(float dt) {
	if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
		data->machine->AddState(StateRef(new MainMenuState()));
	}
}

void SplashState::Draw(float dt) {
	data->window->clear();
	data->window->draw(_background);
	data->window->display();
}