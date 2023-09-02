#include "SoundManager.h"
#include "GameData.h"

SoundManager::SoundManager() 
{
	this->LoadSounds();
}

void SoundManager::LoadSounds() {
	
}

void SoundManager::PlaySound(const std::string& name)
{
	data->assets->PlaySound(name);
}
