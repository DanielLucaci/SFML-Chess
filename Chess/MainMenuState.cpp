#include "MainMenuState.h"
#include "PlayState.h"

MainMenuState::MainMenuState(GameDataRef data): _data(data) { 
	this->Init();
}

void MainMenuState::Init() {
	this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Play Button Hover", PLAY_BUTTON_HOVER_FILEPATH);

	_background.setTexture(_data->assets.GetTexture("Main Menu Background"));
	_playButton.setTexture(_data->assets.GetTexture("Play Button"));
	_playButton.setPosition(
		(int)(SCREEN_WIDTH / 2.f - _playButton.getLocalBounds().width / 2.f), 
		(int)(SCREEN_HEIGHT / 2.f - _playButton.getLocalBounds().height / 2.f)
	);
}

void MainMenuState::HandleInput() {
	sf::Event event; 
	while (_data->window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				_data->window->close();
				break;
			case sf::Event::MouseButtonPressed:
				// Resume
				if (_data->input.isSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) {
					_data->machine.AddState(StateRef(new PlayState(_data)));
				}
				break;
			case sf::Event::MouseMoved:
				if (_data->input.isSpriteHovered(_playButton, _data->window))
					_playButton.setTexture(_data->assets.GetTexture("Play Button Hover"));
				else
					_playButton.setTexture(_data->assets.GetTexture("Play Button"));
				break;
			default:
				break;
		}
	}
}

void MainMenuState::Update(float dt) {
	
}

void MainMenuState::Draw(float dt) {
	_data->window->clear();
	_data->window->draw(_background);
	_data->window->draw(_playButton);
	_data->window->display();
}