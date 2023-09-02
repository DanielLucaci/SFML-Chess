#include "SplashState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include <iostream>
#include "GameData.h"

void SplashState::LoadAssets() 
{
	// Load Textures
	data->assets->LoadTexture("Black Pawn", BLACK_PAWN_FILEPATH);
	data->assets->LoadTexture("Black Bishop", BLACK_BISHOP_FILEPATH);
	data->assets->LoadTexture("Black Rook", BLACK_ROOK_FILEPATH);
	data->assets->LoadTexture("Black Knight", BLACK_KNIGHT_FILEPATH);
	data->assets->LoadTexture("Black Queen", BLACK_QUEEN_FILEPATH);
	data->assets->LoadTexture("Black King", BLACK_KING_FILEPATH);
	data->assets->LoadTexture("White Pawn", WHITE_PAWN_FILEPATH);
	data->assets->LoadTexture("White Bishop", WHITE_BISHOP_FILEPATH);
	data->assets->LoadTexture("White Rook", WHITE_ROOK_FILEPATH);
	data->assets->LoadTexture("White Knight", WHITE_KNIGHT_FILEPATH);
	data->assets->LoadTexture("White Queen", WHITE_QUEEN_FILEPATH);
	data->assets->LoadTexture("White King", WHITE_KING_FILEPATH);
	data->assets->LoadTexture("Table", PLAY_STATE_BACKGROUND_FILEPATH);

	data->assets->LoadTexture("Main Menu Background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
	data->assets->LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
	data->assets->LoadTexture("Play Button Hover", PLAY_BUTTON_HOVER_FILEPATH);

	// Load Fonts
	data->assets->LoadFont("Times New Roman", TIMES_NEW_ROMAN_FONT_FILEPATH);

	// Load Sounds
	data->assets->LoadSound("Capture", CAPTURE_SOUND_FILEPATH);
	data->assets->LoadSound("Check", CHECK_SOUND_FILEPATH);
	data->assets->LoadSound("Invalid", INVALID_SOUND_FILEPATH);
	data->assets->LoadSound("Lose", LOSE_SOUND_FILEPATH);
	data->assets->LoadSound("Move", MOVE_SOUND_FILEPATH);
	data->assets->LoadSound("Win", WIN_SOUND_FILEPATH);
}

SplashState::SplashState(): _isLoadCompleted(false)
{
	_loadThread = std::thread([this]() {
		// Load assets asynchronously in this thread
		LoadAssets();
	  
		_isLoadCompleted = true;
	});

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
	// if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
	//	data->machine->AddState(StateRef(new MainMenuState()));
	// }
	if(_isLoadCompleted) 
	{
		data->machine->AddState(StateRef(new MainMenuState()));
	}
}

void SplashState::Draw(float dt) {
	data->window->clear();
	data->window->draw(_background);
	data->window->display();
}