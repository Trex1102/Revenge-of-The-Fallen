#include "StateMachine.h"

namespace GameEngine {
	void GameEngine::StateMachine::AddState(StateRef newstate, bool isReplacing)
	{
		this->is_adding = true;
		this->is_replacing = isReplacing;
		this->newState = move(newstate);
	}

	void GameEngine::StateMachine::RemoveState()
	{
		this->is_removing = true;
	}

	void GameEngine::StateMachine::ProcessStateChanges()
	{
		if (this->is_removing && !this->states.empty()) {

			this->states.top()->Pause();
			this->states.pop();
			if (!this->states.empty()) {
				this->states.top()->Resume();
			}
			this->is_removing = false;

		}
		if (this->is_adding) {
			if (!this->states.empty()) {
				if (this->is_replacing) {
					this->states.top()->Pause();
					this->states.pop();
				}
				else {
					this->states.top()->Pause();
				}
			}
			this->states.push(move(this->newState));
			this->is_adding = false;
			this->states.top()->Init(); // starting
		}
	}

	StateRef& GameEngine::StateMachine::GetActiveState()
	{
		if (!states.empty()) {
			return this->states.top();
		}
	}
}
