#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <map>
#include <iostream>
#include <cassert>
#include <stack>
#include <memory>
using namespace std;
using namespace sf;
#include "State.h"
namespace GameEngine {

	typedef unique_ptr<State> StateRef;
	class StateMachine {
	public:
		StateMachine() {}
		~StateMachine() {}


		void AddState(StateRef newstate, bool isReplacing = true);
		void RemoveState();

		void ProcessStateChanges();


		StateRef& GetActiveState();

	private:
		stack<StateRef> states;
		StateRef newState;

		bool is_removing;
		bool is_adding;
		bool is_replacing;
	};
}
