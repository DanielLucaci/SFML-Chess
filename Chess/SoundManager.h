#pragma once
#include <string>

class SoundManager
{
public:
	SoundManager();	
	void PlaySound(const std::string&);
private:
	void LoadSounds();
};

