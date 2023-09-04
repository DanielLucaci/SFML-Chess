#pragma once
#include "EventHandler.h"

class PlayStateEventHandler: public EventHandler
{
public:
	PlayStateEventHandler(State* state);
	
	void handleMouseButtonPressed() override;
	void handleMouseButtonReleased();
};

