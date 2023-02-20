#include "SoundManager.h"

SoundManager::SoundManager(GameDataRef data): _data(data)
{
	this->LoadSounds();
}

void SoundManager::LoadSounds() {
	this->_data->assets.LoadSound("Capture", CAPTURE_SOUND_FILEPATH);
	this->_data->assets.LoadSound("Check", CHECK_SOUND_FILEPATH);
	this->_data->assets.LoadSound("Invalid", INVALID_SOUND_FILEPATH);
	this->_data->assets.LoadSound("Lose", LOSE_SOUND_FILEPATH);
	this->_data->assets.LoadSound("Move", MOVE_SOUND_FILEPATH);
	this->_data->assets.LoadSound("Win", WIN_SOUND_FILEPATH);
}

void SoundManager::PlaySound(const std::string& name)
{
	this->_data->assets.PlaySound(name);
}
