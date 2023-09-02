#pragma once
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "UIManager.h"

class GameData {

public:
	AssetManager* assets;
	StateMachine* machine;
	WindowRef window;
	InputManager* input;
	UIManager* ui;

	GameData(const GameData&) = delete;

	~GameData();

	static GameData* getInstance();

private:  
	static GameData* instance;

	GameData();
};

extern const GameData* const data;