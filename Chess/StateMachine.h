#pragma once
#include "State.h"
#include <memory>
#include <stack>

typedef std::unique_ptr<State> StateRef;
typedef std::stack<StateRef> States;

class StateMachine
{
public:
	StateMachine() = default;
	~StateMachine() = default;

	void AddState(StateRef newState, bool isReplacing = true);
	void RemoveState();
	void ProcessStateChanges();

	StateRef& GetActiveState();
private:
	States _states;
	StateRef _newState;

	bool _isRemoving;
	bool _isReplacing;
	bool _isAdding;
};

