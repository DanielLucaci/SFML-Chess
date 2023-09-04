#pragma once
#include "EventHandler.h"

class MainMenuStateEventHandler: public EventHandler
{
public:
	MainMenuStateEventHandler(State* state);

	void handleMouseButtonPressed() override;
};

