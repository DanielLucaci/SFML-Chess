#include "SoundManager.h"
#include "GameData.h"

SoundManager::SoundManager() 
{
	this->LoadSounds();
}

void SoundManager::LoadSounds() {
	data->assets->LoadSound("Capture", CAPTURE_SOUND_FILEPATH);
	data->assets->LoadSound("Check", CHECK_SOUND_FILEPATH);
	data->assets->LoadSound("Invalid", INVALID_SOUND_FILEPATH);
	data->assets->LoadSound("Lose", LOSE_SOUND_FILEPATH);
	data->assets->LoadSound("Move", MOVE_SOUND_FILEPATH);
	data->assets->LoadSound("Win", WIN_SOUND_FILEPATH);
}

void SoundManager::PlaySound(const std::string& name)
{
	data->assets->PlaySound(name);
}
