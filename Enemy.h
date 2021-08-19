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
#include <vector>
#include <utility>
#include "Collision.h"
using namespace std;
using namespace sf;
using namespace GameEngine;

namespace rotf {
	class Enemy : public Entity {
	public:
		Enemy(GameDataRef data) : data(data) {};
		virtual ~Enemy() {};


		void Init();
		

		void Animation() {
			animator = new Animator(this->enemy1[0], Vector2i(85, 94), Vector2i(4, 2), Vector2i(0, 0), 8, seconds(1.1), true);
		}
		void Draw();

		void Update() {
			//enemy001
			if (!enemy001_pos.empty()) {
				for (int i = 0; i < enemy001_pos.size(); i++) {

					if (enemy001_pos[i].first <= 570) isclose = true;
					
					if (enemy001_pos[i].first >= 770) isclose = false;

					if ((rand() % 50) == 45) isvanish = true;
					else if(!isclose)isvanish = false;

					if (player_pos >= enemy001_entry[i].first) {
						enemy001_entry[i].second = true;
					}


					if (enemy001_entry[i].second) {

						if (isclose == false) {
							enemy001_pos[i].first -= deltatime * (speed);

							if (Keyboard::isKeyPressed(Keyboard::A)) {
								enemy001_pos[i].first += deltatime;

							}

							if (Keyboard::isKeyPressed(Keyboard::D)) {
								enemy001_pos[i].first -= deltatime * speed;

							}
						}
						else if (isclose == true && isvanish == true) {

							logic(enemy001_pos[i]);
							
							
						}


						if (enemy001_pos[i].first <= 0.0) {
							enemy001_pos.erase(enemy001_pos.begin());
							enemy001_entry.erase(enemy001_entry.begin());
							

						}


					}
					if ( enemy001_pos.size() != 0 && enemy001_entry[i].second == true) {
						enemy1[i].setPosition(Vector2f(enemy001_pos[i].first, enemy001_pos[i].second));
				
					}
				}
			}

		};

		void logic(pair<double,double> &pos) {

			pos.first += deltatime * (speed);
		
		}

		void BulletUpdate(int &hp , int &shield) {
			venomtimer1 -= deltatime;

			if (!enemy001_pos.empty() && venomtimer1 <= 0) {
				for (int i = 0; i < enemy001_pos.size(); i++) {
					if (enemy001_entry[i].second) {
						enemy001_bullet.push_back(make_pair(enemy001_pos[i].first + 10 , enemy001_pos[i].second + 10));
						
					}


				}
				venomtimer1 = 2.0;
			}
			if (!enemy001_bullet.empty()) {
				for (int i = 0; i < enemy001_bullet.size(); i++) {
					if (Keyboard::isKeyPressed(Keyboard::A)) {
						enemy001_bullet[i].first -= deltatime;

					}

					else if (Keyboard::isKeyPressed(Keyboard::D)) {
						enemy001_bullet[i].first -= deltatime * speed;

					}
					else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift)) {
						enemy001_bullet[i].first -= deltatime *3* speed;

					}
					bullets[i].setScale(.15, .15);
					enemy001_bullet[i].first -= deltatime * (speed + 100);
					bullets[i].setPosition(enemy001_bullet[i].first, enemy001_bullet[i].second);

					isgettinghit = Colliding(510, 810, enemy001_bullet[i].first, enemy001_bullet[i].second);

					if (isgettinghit) {
						enemy001_bullet.erase(enemy001_bullet.begin());
						
						if (shield > 0) shield-=5;
						else hp--;
					}

				}
			}
			
			
		}


		//enemy002
		void Update2() {
			
			if (!enemy001_pos.empty()) {
				for (int i = 0; i < enemy001_pos.size(); i++) {

					if (enemy001_pos[i].first <= 570) isclose = true;

					if (enemy001_pos[i].first >= 770) isclose = false;

					if ((rand() % 50) == 45) isvanish = true;
					else if (!isclose)isvanish = false;

					if (player_pos >= enemy001_entry[i].first) {
						enemy001_entry[i].second = true;
					}


					if (enemy001_entry[i].second) {

						if (isclose == false) {
							enemy001_pos[i].first -= deltatime * (speed);

							if (Keyboard::isKeyPressed(Keyboard::A)) {
								enemy001_pos[i].first += deltatime;

							}

							if (Keyboard::isKeyPressed(Keyboard::D)) {
								enemy001_pos[i].first -= deltatime * speed;

							}
						}
						else if (isclose == true && isvanish == true && abilitycount2 <= 6) {

							logic2(enemy001_pos[i]);


						}


						if (enemy001_pos[i].first <= 0.0) {
							enemy001_pos.erase(enemy001_pos.begin());
							enemy001_entry.erase(enemy001_entry.begin());


						}


					}
					if (enemy001_pos.size() != 0 && enemy001_entry[i].second == true) {
						enemy1[i].setPosition(Vector2f(enemy001_pos[i].first, enemy001_pos[i].second));

					}
				}
			}

		};


		void logic2(pair<double,double> &pos) {

			pos.first += (double)500 + (rand() % 300);
			abilitycount2++;

		}


		//enemy003
		void Update3(bool isattacking, int &money) {

			if (!enemy001_pos.empty()) {
				for (int i = 0; i < enemy001_pos.size(); i++) {

					if (enemy001_pos[i].first <= 570) isclose = true;

					if (enemy001_pos[i].first >= 770) isclose = false;

					if ((rand() % 50) == 45) isvanish = true;
					else if (!isclose)isvanish = false;

					if (player_pos >= enemy001_entry[i].first) {
						enemy001_entry[i].second = true;
					}



					if (enemy001_entry[i].second) {

						if (isclose == false) {
							enemy001_pos[i].first -= deltatime * (speed);

							if (Keyboard::isKeyPressed(Keyboard::A)) {
								enemy001_pos[i].first += deltatime;

							}

							if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::LShift)) {
								enemy001_pos[i].first -= deltatime * speed;

							}
							else if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift)) {
								enemy001_pos[i].first -= deltatime * 3* speed;
								

							}
						}
						/*else if (isclose == true && rand()%200 == 1 ) {

							logic3(enemy001_pos[i]);


						}*/




						else if (isclose == true) {
							logic3(enemy001_pos[i]);
						}

						iscolliding = Colliding(530,800,enemy001_pos[i].first, enemy001_pos[i].second);


						damage(isattacking , enemy001_hp[i]);

						if (enemy001_pos[i].first <= 0.0 || enemy001_hp[i] <= 0) {
							enemy001_pos.erase(enemy001_pos.begin());
							enemy001_entry.erase(enemy001_entry.begin());
							money += 30;

						}


					}
					if (enemy001_pos.size() != 0 && enemy001_entry[i].second == true) {
						enemy1[i].setPosition(Vector2f(enemy001_pos[i].first, enemy001_pos[i].second));

					}
				}
			}

		};

		void logic3(pair<double, double> &pos) {
			//pos.first += (double)500 + (rand() % 300);
			abilitycount2++;
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				pos.first += deltatime * speed;

			}

			if (Keyboard::isKeyPressed(Keyboard::D)) {
				pos.first -= deltatime * speed;

			}
		}


		void invisible() {

		}

		void player_invisible() {



		}



		
		
		bool bullet_hit() {

		}



		void damage(bool isattacking , int &hp) {

			if (isattacking && iscolliding) {
				if (superbullet) {
					hp -= 30;
				}
				else hp -= 10;
			} 

		}

		void death(vector<pair<double,double>> &pos, vector<pair<double, double>>& entry) {
			
			
			if (isdead) {


				pos.erase(pos.begin());
				entry.erase(entry.begin());
			}
		}


		void HandleInput(Event &evnt) {
			if (evnt.type == evnt.KeyPressed) {
				if (evnt.key.code == Keyboard::D) {
					
					player_pos++;
				}

				else if (evnt.key.code == Keyboard::A) {
					
					player_pos--;
				}
			}
		}

		Vector2f getpos() {};
		FloatRect getbounds() {};



		Animator* animator;
		vector<pair<double,double>> enemy001_pos;
		vector<pair<double,double>> enemy002_pos;
		vector<pair<double,double>> enemy003_pos;

		vector<pair<double, double>> enemy001_bullet;
		vector<pair<double, double>> enemy002_bullet;
		vector<pair<double, double>> enemy003_bullet;

		vector<int> enemy001_hp;
		vector<int> enemy002_hp;
		vector<int> enemy003_hp;

		vector<pair<bool, bool>> enemy001_abi;
		vector<pair<bool, bool>> enemy002_abi;
		vector<pair<bool, bool>> enemy003_abi;



		vector<pair<double, bool>> enemy001_entry;
		vector<pair<double, bool>> enemy002_entry;
		vector<pair<double, bool>> enemy003_entry;
		Clock time;
		double deltatime = .01;
		double venomtimer1 = 0;
	private:

		GameDataRef data;

		Sprite enemy1[20];
		Sprite enemy2[20];
		Sprite enemy3[20];
		Sprite bullets[51];
		Texture bullet;
		Sprite bullet_body;


		bool isclose;
		bool isfar;
		bool isvanish;
		bool notmoving;
		bool shield;
		bool isnvisible;
		bool isplayerinvisible;
		bool isfiring; 
		int abilitycount2 = 0;
		bool shoting;
		bool isdead;
		bool superattack;
		bool superbullet;
		bool iscolliding;
		bool isgettinghit;

		int player_pos = 0;
		double speed = 100;
		//int hp = 100;
		int souls;

		//bullet
	};
}
