#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <map>
#include <iostream>
#include <cassert>
#include "StateMachine.h"
#include "AssetManager.h"
#include "State.h"
#include "Game.h"
#include "Definations.h"
#include "Animator.h"
#include "Animator2.h"
using namespace std;
using namespace sf;

namespace GameEngine {

	
	class IntroState : public State {
	public:
		IntroState(GameDataRef data);
		~IntroState() {}
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		//Animation Init
		void animation() { 
			animator = new Animator2(this->data, this->intro , 8 , seconds(1) );
		}


		Sprite intro[8];
		
	private:
		GameDataRef data;
		Clock clock;
		
		Sound sound;
		Text text;
		Animator2* animator;


	};
}