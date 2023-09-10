#pragma once
#include "EventHandler.h"

class SplashStateEventHandler: public EventHandler
{
public:
	SplashStateEventHandler(State* state);
	~SplashStateEventHandler() = default;
};
