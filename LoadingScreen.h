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
#include "GameState.h"
using namespace std;
using namespace sf;

namespace GameEngine {
	class LoadingState : public State {
	public:
		LoadingState(GameDataRef data) :data(data) {};
		~LoadingState() {}
		void Init() {
			//loading
			this->data->textures.load("lsbackground", lsbackground);
			this->data->textures.load("bar", lsbars);

			//getting
			this->background.setTexture(this->data->textures.get("lsbackground"));
			this->bar.setTexture(this->data->textures.get("bar"));


			//
			animation();

		}
		void HandleInput() {

		}
		void Update(float dt) {

			Time deltaTime = seconds(dt);

			this->animator->Update(deltaTime);


			if (this->clock.getElapsedTime().asSeconds() > 3.5) {


				this->data->machine.AddState(StateRef(new GameState(data)), true);


			}

		}
		void Draw(float dt) {
			this->data->window.clear();
			this->data->window.draw(this->background);
			this->data->window.draw(this->bar);
			this->data->window.display();
		}

		void animation() {

			animator = new Animator(this->bar, Vector2i(486, 121), Vector2i(1, 8), Vector2i(0, 0), 8, seconds(6), false);
		}

		

		Sprite bar;
		Sprite background;
		

	private:
		GameDataRef data;
		Clock clock;

		Animator* animator;
		

		Sound sound;
		



	};
}