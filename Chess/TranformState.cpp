#include "TranformState.h"
#include "BoxManager.h"

TranformState::TranformState(PlayState* state, GameDataRef data): playState(state), _data(data)
{
	this->Init();
}


