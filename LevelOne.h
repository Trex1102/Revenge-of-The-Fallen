#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <map>
#include <iostream>
#include <cassert>
#include <vector>
#include "StateMachine.h"
#include "AssetManager.h"
#include "State.h"
#include "Game.h"
#include "Definations.h"
#include "InputHandler.h"
using namespace std;
using namespace sf;

namespace rotf {
	class LevelOne {
	public:
		LevelOne(GameDataRef data) : data(data) {};

		void init() {
			// loading
			tbackground[0].loadFromFile(l1background01);
			tbackground[1].loadFromFile(l1background02);
			tbackground[2].loadFromFile(l1background03);
			tbackground[3].loadFromFile(l1background04);

			//repeated on
			tbackground[0].setRepeated(true);
			tbackground[1].setRepeated(true);
			tbackground[2].setRepeated(true);
			tbackground[3].setRepeated(true);


			//getting
			background[0].setTexture(tbackground[0]);
			background[1].setTexture(tbackground[1]);
			background[2].setTexture(tbackground[2]);
			background[3].setTexture(tbackground[3]);

			
			background[0].setPosition(0,-300);
			background[1].setPosition(0, -100);
			background[2].setPosition(0, 300);
			background[3].setPosition(0, 300);
			


			//

			this->data->soundbuffers.load("Level One Background Music", l1backgroundmusic);
			this->background_sound.setBuffer(this->data->soundbuffers.get("Level One Background Music"));
			background_sound.getLoop();
			background_sound.play();
			background_sound.setVolume(80);
		
			
		}

		void HandleInput(Event &evnt) {
			InputHandler input;
			if (evnt.type == evnt.KeyPressed) {
				if (evnt.key.code == Keyboard::D) {
					background[0].setTextureRect(IntRect(posx +=y, 0, width+=y, 1000));
					background[1].setTextureRect(IntRect(posx += y, 0, width += y, 1000));
					background[2].setTextureRect(IntRect(posx += y, 0, width += y, 1000));
					background[3].setTextureRect(IntRect(posx += y, 0, width += y, 1000));

				}
				
				else if (evnt.key.code == Keyboard::A) {
					background[0].setTextureRect(IntRect(posx -= y, 0, width -= y, 1080));
					background[1].setTextureRect(IntRect(posx -= y, 0, width -= y, 1080));
					background[2].setTextureRect(IntRect(posx -= y, 0, width -= y, 1080));
					background[3].setTextureRect(IntRect(posx -= y, 0, width -= y, 1080));
				
				}
				
			}
			if (input.DDown && input.LShiftDown) {
				background[0].setTextureRect(IntRect(posx += x, 0, width += x, 1000));
				background[1].setTextureRect(IntRect(posx += x, 0, width += x, 1000));
				background[2].setTextureRect(IntRect(posx += x, 0, width += x, 1000));
				background[3].setTextureRect(IntRect(posx += x, 0, width += x, 1000));

			}

		}

		void draw() {
			//this->data->window.draw(background[0]);
			//this->data->window.draw(background[1]);
			this->data->window.draw(background[2]);
			this->data->window.draw(background[3]);
		}
		Sound background_sound;
	private:
		GameDataRef data;
		Texture tbackground[5];
		Sprite background[5];
		const float x = 2.5;
		const float y = 1.5;
		int width = 1920;
		int posx = 0;
		
	};
}