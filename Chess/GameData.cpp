#include "GameData.h"

GameData* GameData::instance = nullptr;

GameData* GameData::getInstance()
{
	if (instance == nullptr) {
		instance = new GameData();
	}
	return instance;
}

GameData::~GameData()
{
	if (instance != nullptr) {
		delete(instance);
	}

	delete(assets);
	delete(machine);
	delete(ui);
	delete(input);
}

GameData::GameData() {
	this->window = std::make_shared<sf::RenderWindow>();
	this->ui = new UIManager(this->window);
	this->machine = new StateMachine();
	this->input = new InputManager();
	this->assets = new AssetManager();
}

const GameData* const data = GameData::getInstance();