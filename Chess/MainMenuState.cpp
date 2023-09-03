#include "MainMenuState.h"
#include "PlayState.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "StateManager.h"
#include "WindowManager.h"

// TODO: Inject window

MainMenuState::MainMenuState()
{
	this->Init();
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
	sf::Event event; 
	while (window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseButtonPressed:
				// Resume
				if (inputManager->isSpriteClicked(_playButton, sf::Mouse::Left)) {
					stateManager->AddState(StateRef(new PlayState()));
				}
				break;
			case sf::Event::MouseMoved:
				if (inputManager->isSpriteHovered(_playButton))
					_playButton.setTexture(assetManager->GetTexture("Play Button Hover"));
				else
					_playButton.setTexture(assetManager->GetTexture("Play Button"));
				break;
			default:
				break;
		}
	}
}

void MainMenuState::Update(float dt) {
	
}

void MainMenuState::Draw(float dt) {
	window->clear();
	window->draw(_background);
	window->draw(_playButton);
	window->display();
}