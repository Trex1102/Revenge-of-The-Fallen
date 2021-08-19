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
#include "Entity.h"
#include "InputHandler.h"
#include "Collision.h"
using namespace std;
using namespace sf;
using namespace GameEngine;

namespace rotf {
	struct spells {
		/*
		int firebolt = 0;
		int shadow = 0;
		int iceshards = 0;
		int shield;
		int superbullet;*/

		pair<int, int> firebolt;
		pair<int, int> shadow;
		pair<int, int> iceshards;
		pair<int, int> revive;
		pair<int, int> nature;
		pair<int, int >  wind;
		pair<int, int> electricity;
		pair<int, int> lighting;
	};
	class Player:public Entity {
	public:
		Player(GameDataRef data);
		virtual ~Player() {};
		 
		void Init(); // Init the player related data
		void animation() {
			animator = new Animator(this->player_animation, Vector2i(147, 96), Vector2i(11, 1), Vector2i(0, 0), 11, seconds(1.1), true);
		}
		void Draw();
		void HandleInput(Event &evnt);  // input
		void Update(); // logic
		Vector2f getpos();
		FloatRect getbounds();
		void player_move(float x, float y) {
			this->player.move(x, y);
		}

		void Health(); 
		int hp = 100;

		int shield = 100;
		int money = 0;
		int magicpower = 0;

		int player_pos = 0;
		//update

		
		//void PlayerInfo();

		void damage(bool superbullet) {
			 
			
			if (hp <= 0) {
				isdead = true;
				return;
			}
			
			if ( !superbullet ) {
				if (isbullethit()) {
					if (shield > 0) {
						shield -= 10;
					}
					else {
						hp -= 10;
					}
				}
			}
			else {
				if (isbullethit()) {
					if (shield > 0) {
						shield -= 30;
					}
					else {
						hp -= 30;
					}
				}
			}
			
		}
		


		bool isbullethit() {

		}



		void money_logic() {

		}




		void BuySpell() {
			InputHandler input;
			if (input.CltrlDown && input.OneDown) {
				if (money >= spells.firebolt.first) spells.firebolt.second++;
				else {
					// draw not enough money
				}
			}
			if (input.CltrlDown && input.TwoDown) {
				if (money >= spells.electricity.first) spells.electricity.second++;
				else {
					// draw not enough money
				}
			}
			if (input.CltrlDown && input.ThreeDown) {
				if (money >= spells.iceshards.first) spells.iceshards.second++;
				else {
					// draw not enough money
				}
			}
			if (input.CltrlDown && input.FourDown) {
				if (money >= spells.lighting.first) spells.lighting.second++;
				else {
					// draw not enough money
				}
			}
			if (input.CltrlDown && input.FiveDown) {
				if (money >= spells.revive.first) spells.revive.second++;
				else {
					// draw not enough money
				}
			}

		}

		void UsingSpell() {
			InputHandler input;
			Clock clock;
			if (input.OneDown) {
				if (spells.firebolt.second >= 1) {

					while (clock.getElapsedTime().asSeconds() <= 3) {
						// draw fireobolt
					}

					spells.firebolt.second--;
				}
				else {
					// No spells
				}
				
			}
			if (input.TwoDown) {
				if (spells.electricity.second >= 1) {

					while (clock.getElapsedTime().asSeconds() <= 3) {
						// draw fireobolt
					}

					spells.electricity.second--;
				}
				else {
					// No spells
				}

			}
			if (input.ThreeDown) {
				if (spells.iceshards.second >= 1) {

					while (clock.getElapsedTime().asSeconds() <= 3) {
						// draw fireobolt
					}

					spells.iceshards.second--;
				}
				else {
					// No spells
				}

			}
			if (input.FourDown) {
				if (spells.lighting.second >= 1) {

					while (clock.getElapsedTime().asSeconds() <= 3) {
						// draw fireobolt
					}

					spells.lighting.second--;
				}
				else {
					// No spells
				}

			}
			if (input.FiveDown) {
				if (spells.revive.second >= 1) {

					while (clock.getElapsedTime().asSeconds() <= 3) {
						// draw fireobolt
					}

					spells.revive.second--;
				}
				else {
					// No spells
				}

			}
		}



		//update stop
		//animations
		bool superbullet= false;
		Animator* animator;
		int scores;
		bool iswalkingfor = false, iswalkingback = false , isidle = true , isrunningfor = false,isrunningback = false, isattacking = false;
		bool ishowling = false , isdead = false;


		string player_name;
		Sound howl, yelp;

		spells spells;
	private:
		int n = 0;
		//game data
		GameDataRef data;
		

		//spells
		


		//sprites
		Sprite player;
		Sprite player_animation;
		Sprite score_animation;
		Sprite firebolt;
		Sprite electricity;
		Sprite iceshards;
		Sprite lighting;
		Sprite nature;
		Sprite revive;
		Sprite shadow;
		Sprite wind;

		

		//player related information
		float Velocity;


		int souls;

		Font font;
		Text not_enough;
		

	};
}
