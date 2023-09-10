#include "SplashState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include <iostream>
#include "StateManager.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "SplashStateEventHandler.h"

void SplashState::LoadAssets() 
{
	// Load Textures
	assetManager->LoadTexture("Black Pawn", BLACK_PAWN_FILEPATH);
	assetManager->LoadTexture("Black Bishop", BLACK_BISHOP_FILEPATH);
	assetManager->LoadTexture("Black Rook", BLACK_ROOK_FILEPATH);
	assetManager->LoadTexture("Black Knight", BLACK_KNIGHT_FILEPATH);
	assetManager->LoadTexture("Black Queen", BLACK_QUEEN_FILEPATH);
	assetManager->LoadTexture("Black King", BLACK_KING_FILEPATH);
	assetManager->LoadTexture("White Pawn", WHITE_PAWN_FILEPATH);
	assetManager->LoadTexture("White Bishop", WHITE_BISHOP_FILEPATH);
	assetManager->LoadTexture("White Rook", WHITE_ROOK_FILEPATH);
	assetManager->LoadTexture("White Knight", WHITE_KNIGHT_FILEPATH);
	assetManager->LoadTexture("White Queen", WHITE_QUEEN_FILEPATH);
	assetManager->LoadTexture("White King", WHITE_KING_FILEPATH);
	assetManager->LoadTexture("Table", PLAY_STATE_BACKGROUND_FILEPATH);

	assetManager->LoadTexture("Main Menu Background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
	assetManager->LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
	assetManager->LoadTexture("Play Button Hover", PLAY_BUTTON_HOVER_FILEPATH);

	// Load Fonts
	assetManager->LoadFont("Times New Roman", TIMES_NEW_ROMAN_FONT_FILEPATH);

	// Load Sounds
	assetManager->LoadSound("Capture", CAPTURE_SOUND_FILEPATH);
	assetManager->LoadSound("Check", CHECK_SOUND_FILEPATH);
	assetManager->LoadSound("Invalid", INVALID_SOUND_FILEPATH);
	assetManager->LoadSound("Lose", LOSE_SOUND_FILEPATH);
	assetManager->LoadSound("Move", MOVE_SOUND_FILEPATH);
	assetManager->LoadSound("Win", WIN_SOUND_FILEPATH);
}

SplashState::SplashState(): _isLoadCompleted(false)
{
	_loadThread = std::thread([this]() {
		LoadAssets();	  
		_isLoadCompleted = true;
	});
    
	this->eventHandler = new SplashStateEventHandler(this);
	this->Init();
}

void SplashState::Init() {
	assetManager->LoadTexture("Splash State Background", SPLASH_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(assetManager->GetTexture("Splash State Background"));
}

void SplashState::HandleInput() {
	eventHandler->handleInput();
}

void SplashState::Update(float dt) 
{	
	if(_isLoadCompleted) 
		stateManager->AddState(StateRef(new MainMenuState()));
}

void SplashState::Draw(float dt) {
	window->clear();
	window->draw(_background);
	window->display();
}