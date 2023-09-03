#include "SoundManager.h"
#include "AssetManager.h"

SoundManager::SoundManager() 
{
	this->LoadSounds();
}

void SoundManager::LoadSounds() {
	
}

void SoundManager::PlaySound(const std::string& name)
{
	assetManager->PlaySound(name);
}
