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
#include "Player.h"
#include "Bullet.h"
#include "Bars.h"
#include "LevelOne.h"
#include "DarkSaber.h"
#include "Animator2.h"
#include "Enemy.h"
using namespace std;
using namespace sf;
using namespace rotf;

namespace GameEngine {
	class GameState:public State {
	public:
		GameState(GameDataRef data);
		~GameState() {};
		void Init(); // Init All
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		void Animation() {
			dswalk = new Animator2(this->data, this->darksaber->dswalk, 38, seconds(2));
			dsidle = new Animator2(this->data, this->darksaber->dsidle, 100, seconds(5));
			dsrun = new Animator2(this->data, this->darksaber->dsrun, 17, seconds(1));
			dsattack = new Animator2(this->data, this->darksaber->dsattack, 77, seconds(3));
			dshowl = new Animator2(this->data, this->darksaber->dshowl, 20, seconds(1.2));
		}
		//player


		//bullet
		void UpdateBullets();
		
		void Pause() {
			this->levelone->background_sound.pause();
		}
		void Resume() {
			this->levelone->background_sound.play();
		}


	private:
		GameDataRef data;
		Clock clock;
		Healthbar *healthbar;
		Shieldbar* shieldbar;
		Magicbar* magicbar;
		Moneybar* moneybar;
		Spellbar* spellbar;

		//World
		LevelOne* levelone;
		
		//weapon
		Texture bullet;

		//Sprite Enemy;
		Sprite PlayButtonOuter;
		Sound sound;
		Text text;

		//player
		Player *player;
		DarkSaber* darksaber;
		
		//ds
		Animator2* dswalk;
		Animator2* dsidle;
		Animator2* dsrun;
		Animator2* dsattack;
		Animator2* dshowl;

		//enemy

		Enemy *enemy;

		//bullet
		vector <Bullet*> bullets;

		//

	};
}
