#pragma once
#include "GameData.h"

class SoundManager
{
public:
	SoundManager(GameDataRef);	
	void PlaySound(const std::string&);
private:
	void LoadSounds();

	GameDataRef _data;
};

