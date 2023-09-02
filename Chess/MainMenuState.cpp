#include "MainMenuState.h"
#include "PlayState.h"
#include "GameData.h"

MainMenuState::MainMenuState()
{
	this->Init();
}

void MainMenuState::Init() 
{
	_background.setTexture(data->assets->GetTexture("Main Menu Background"));
	_playButton.setTexture(data->assets->GetTexture("Play Button"));
	_playButton.setPosition(
		(int)(SCREEN_WIDTH / 2.f - _playButton.getLocalBounds().width / 2.f), 
		(int)(SCREEN_HEIGHT / 2.f - _playButton.getLocalBounds().height / 2.f)
	);
}

void MainMenuState::HandleInput() {
	sf::Event event; 
	while (data->window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				data->window->close();
				break;
			case sf::Event::MouseButtonPressed:
				// Resume
				if (data->input->isSpriteClicked(_playButton, sf::Mouse::Left, data->window)) {
					data->machine->AddState(StateRef(new PlayState()));
				}
				break;
			case sf::Event::MouseMoved:
				if (data->input->isSpriteHovered(_playButton, data->window))
					_playButton.setTexture(data->assets->GetTexture("Play Button Hover"));
				else
					_playButton.setTexture(data->assets->GetTexture("Play Button"));
				break;
			default:
				break;
		}
	}
}

void MainMenuState::Update(float dt) {
	
}

void MainMenuState::Draw(float dt) {
	data->window->clear();
	data->window->draw(_background);
	data->window->draw(_playButton);
	data->window->display();
}