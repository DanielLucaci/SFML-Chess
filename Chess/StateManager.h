#pragma once
#include "State.h"
#include <memory>
#include <stack>

typedef std::unique_ptr<State> StateRef;
typedef std::stack<StateRef> States;

class StateManager
{
public:
	~StateManager();

	static StateManager* getInstance();

	void AddState(StateRef, bool = true);
	void RemoveState();
	void ProcessStateChanges();

	StateRef& GetActiveState();
private:
	StateManager() = default;

	static StateManager* _instance;

	States _states;
	StateRef _newState;

	bool _isRemoving;
	bool _isReplacing;
	bool _isAdding;
};

extern StateManager* const stateManager;