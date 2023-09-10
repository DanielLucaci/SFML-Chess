#pragma once
#include "EventHandler.h"
#include "PlayState.h"
#include <functional>

class PlayStateEventHandler: public EventHandler
{
public:
	PlayStateEventHandler(PlayState* state);
	
	void handleMouseButtonPressed();
	void handleMouseButtonReleased();

	std::function<void(float)> update;
	bool& _lockClick;
};

