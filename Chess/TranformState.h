#pragma once
#include "State.h"
#include "PlayState.h"
#include "SFML/Graphics.hpp"

class TranformState : public State
{
public:
	TranformState(PlayState*, GameDataRef);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
private: 


};

