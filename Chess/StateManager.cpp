#include "StateManager.h"

StateManager* StateManager::_instance = nullptr;

StateManager* const stateManager = StateManager::getInstance();

StateManager::~StateManager() 
{
	if (_instance != nullptr)
		delete(_instance);
}

StateManager* StateManager::getInstance() {
	if (_instance == nullptr)
		_instance = new StateManager();
	return _instance;
}

void StateManager::AddState(StateRef newState, bool isReplacing) {
	this->_isAdding = true;
	this->_isReplacing = isReplacing;
	this->_newState = std::move(newState);
}

void StateManager::RemoveState() {
	this->_isRemoving = true;
}

void StateManager::ProcessStateChanges() {
	if (this->_isRemoving && !this->_states.empty()) {
		this->_states.pop();
		if (!this->_states.empty()) {
			this->_states.top()->Resume();
		}
		this->_isReplacing = true;
	}

	if (this->_isAdding) {
		if (!this->_states.empty()) {
			if (this->_isReplacing) {
				this->_states.pop();
			}
			else {
				this->_states.top()->Pause();
			}
		}

		this->_states.push(std::move(this->_newState));
		this->_isAdding = false;
	}
}

StateRef& StateManager::GetActiveState() {
	return this->_states.top();
}