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
#include "IntegerToString.h"
#include "InputHandler.h"


using namespace std;
using namespace sf;
using namespace GameEngine;

namespace rotf {
	class Healthbar {
	public:
		Healthbar(GameDataRef data) : data(data) {};

		void init() {
			// loading
			this->data->textures.load("healthbar1", healthbar01);
			this->data->textures.load("healthbar2", healthbar02);
			this->data->textures.load("healthbar3", healthbar03);
			this->data->textures.load("healthbar4", healthbar04);
			this->data->textures.load("healthbar5", healthbar05);
			this->data->textures.load("healthbar6", healthbar06);
			this->data->textures.load("healthbar7", healthbar07);
			this->data->textures.load("healthbar8", healthbar08);
			this->data->textures.load("healthbar9", healthbar09);
			this->data->textures.load("healthbar10", healthbar10);
			this->data->textures.load("healthbar11", healthbar11);


			//getting
			this->healthbar[0].setTexture(this->data->textures.get("healthbar1"));
			this->healthbar[1].setTexture(this->data->textures.get("healthbar2"));
			this->healthbar[2].setTexture(this->data->textures.get("healthbar3"));
			this->healthbar[3].setTexture(this->data->textures.get("healthbar4"));
			this->healthbar[4].setTexture(this->data->textures.get("healthbar5"));
			this->healthbar[5].setTexture(this->data->textures.get("healthbar6"));
			this->healthbar[6].setTexture(this->data->textures.get("healthbar7"));
			this->healthbar[7].setTexture(this->data->textures.get("healthbar8"));
			this->healthbar[8].setTexture(this->data->textures.get("healthbar9"));
			this->healthbar[9].setTexture(this->data->textures.get("healthbar10"));
			this->healthbar[10].setTexture(this->data->textures.get("healthbar11"));


			//resizing

			healthbar[0].setScale(.10, .10);
			healthbar[0].setPosition(10, 0);
			healthbar[1].setScale(.10, .10);
			healthbar[1].setPosition(10, 0);
			healthbar[2].setScale(.10, .10);
			healthbar[2].setPosition(10, 0);
			healthbar[3].setScale(.10, .10);
			healthbar[3].setPosition(10, 0);
			healthbar[4].setScale(.10, .10);
			healthbar[4].setPosition(10, 0);
			healthbar[5].setScale(.10, .10);
			healthbar[5].setPosition(10, 0);
			healthbar[6].setScale(.10, .10);
			healthbar[6].setPosition(10, 0);
			healthbar[7].setScale(.10, .10);
			healthbar[7].setPosition(10, 0);
			healthbar[8].setScale(.10, .10);
			healthbar[8].setPosition(10, 0);
			healthbar[9].setScale(.10, .10);
			healthbar[9].setPosition(10, 0);
			healthbar[10].setScale(.10, .10);
			healthbar[10].setPosition(10, 0);

		}

		void draw(int hp) {
			if (hp == 00) {
				this->data->window.draw(healthbar[0]);
			}
			if (hp <= 10 && hp > 0 ) {
				this->data->window.draw(healthbar[1]);
			}
			if (hp <= 20 && hp > 10) {
				this->data->window.draw(healthbar[2]);
			}
			if (hp <= 30 && hp > 20) {
				this->data->window.draw(healthbar[3]);
			}
			if (hp <= 40 && hp > 30) {
				this->data->window.draw(healthbar[4]);
			}
			if (hp <= 50 && hp > 40) {
				this->data->window.draw(healthbar[5]);
			}
			if (hp <= 60 && hp>50) {
				this->data->window.draw(healthbar[6]);
			}
			if (hp <= 70 && hp > 60) {
				this->data->window.draw(healthbar[7]);
			}
			if (hp <= 80 && hp> 70) {
				this->data->window.draw(healthbar[8]);
			}
			if (hp <= 90 && hp>80) {
				this->data->window.draw(healthbar[9]);
			}
			if (hp <= 100 && hp > 90) {
				this->data->window.draw(healthbar[10]);
			}

		}
	private:
		GameDataRef data;

		Sprite healthbar[11];
	};

	class Magicbar {
	public:
		Magicbar(GameDataRef data) : data(data) {};

		void init() {

			//loading
			this->data->textures.load("magicbar1", magicbar01);
			this->data->textures.load("magicbar2", magicbar02);
			this->data->textures.load("magicbar3", magicbar03);
			this->data->textures.load("magicbar4", magicbar04);

			// getting
			this->magicbar[0].setTexture(this->data->textures.get("magicbar1"));
			this->magicbar[1].setTexture(this->data->textures.get("magicbar2"));
			this->magicbar[2].setTexture(this->data->textures.get("magicbar3"));
			this->magicbar[3].setTexture(this->data->textures.get("magicbar4"));


			// resizing
			magicbar[0].setScale(.10, .10);
			magicbar[0].setPosition(10, 104);
			magicbar[1].setScale(.10, .10);
			magicbar[1].setPosition(10, 104);
			magicbar[2].setScale(.10, .10);
			magicbar[2].setPosition(10, 104);
			magicbar[3].setScale(.10, .10);
			magicbar[3].setPosition(10, 104);

		}

		void draw(int magicpower) {
			if (magicpower == 00 ) {
				this->data->window.draw(magicbar[0]);
			}
			if (magicpower <= 25 && magicpower > 0) {
				this->data->window.draw(magicbar[1]);
			}
			if (magicpower <= 75 && magicpower > 25) {
				this->data->window.draw(magicbar[2]);
			}
			if (magicpower <= 100 && magicpower >75) {
				this->data->window.draw(magicbar[3]);
			}
		}

	private:
		GameDataRef data;

		Sprite magicbar[5];
	};

	class Shieldbar {
	public:
		Shieldbar(GameDataRef data) : data(data) {};

		void init() {


			//loading
			this->data->textures.load("shieldbar1", shieldbar01);
			this->data->textures.load("shieldbar2", shieldbar02);
			this->data->textures.load("shieldbar3", shieldbar03);
			this->data->textures.load("shieldbar4", shieldbar04);
			this->data->textures.load("shieldbar5", shieldbar05);
			this->data->textures.load("shieldbar6", shieldbar06);
			this->data->textures.load("shieldbar7", shieldbar07);
			this->data->textures.load("shieldbar8", shieldbar08);
			this->data->textures.load("shieldbar9", shieldbar09);
			this->data->textures.load("shieldbar10", shieldbar10);
			this->data->textures.load("shieldbar11", shieldbar11);

			//getting
			this->shieldbar[0].setTexture(this->data->textures.get("shieldbar1"));
			this->shieldbar[1].setTexture(this->data->textures.get("shieldbar2"));
			this->shieldbar[2].setTexture(this->data->textures.get("shieldbar3"));
			this->shieldbar[3].setTexture(this->data->textures.get("shieldbar4"));
			this->shieldbar[4].setTexture(this->data->textures.get("shieldbar5"));
			this->shieldbar[5].setTexture(this->data->textures.get("shieldbar6"));
			this->shieldbar[6].setTexture(this->data->textures.get("shieldbar7"));
			this->shieldbar[7].setTexture(this->data->textures.get("shieldbar8"));
			this->shieldbar[8].setTexture(this->data->textures.get("shieldbar9"));
			this->shieldbar[9].setTexture(this->data->textures.get("shieldbar10"));
			this->shieldbar[10].setTexture(this->data->textures.get("shieldbar11"));


			//resing
			shieldbar[0].setScale(.10, .10);
			shieldbar[0].setPosition(10, 52);
			shieldbar[1].setScale(.10, .10);
			shieldbar[1].setPosition(10, 52);
			shieldbar[2].setScale(.10, .10);
			shieldbar[2].setPosition(10, 52);
			shieldbar[3].setScale(.10, .10);
			shieldbar[3].setPosition(10, 52);
			shieldbar[4].setScale(.10, .10);
			shieldbar[4].setPosition(10, 52);
			shieldbar[5].setScale(.10, .10);
			shieldbar[5].setPosition(10, 52);
			shieldbar[6].setScale(.10, .10);
			shieldbar[6].setPosition(10, 52);
			shieldbar[7].setScale(.10, .10);
			shieldbar[7].setPosition(10, 52);
			shieldbar[8].setScale(.10, .10);
			shieldbar[8].setPosition(10, 52);
			shieldbar[9].setScale(.10, .10);
			shieldbar[9].setPosition(10, 52);
			shieldbar[10].setScale(.10, .10);
			shieldbar[10].setPosition(10, 52);
		}

		void draw(int shield) {
			if (shield == 00) {
				this->data->window.draw(shieldbar[0]);
			}
			if (shield <= 10 && shield > 0) {
				this->data->window.draw(shieldbar[1]);
			}
			if (shield <= 20 && shield > 10) {
				this->data->window.draw(shieldbar[2]);
			}
			if (shield <= 30 && shield > 20) {
				this->data->window.draw(shieldbar[3]);
			}
			if (shield <= 40 && shield > 30) {
				this->data->window.draw(shieldbar[4]);
			}
			if (shield <= 50 && shield > 40) {
				this->data->window.draw(shieldbar[5]);
			}
			if (shield <= 60 && shield > 50) {
				this->data->window.draw(shieldbar[6]);
			}
			if (shield <= 70 && shield > 60) {
				this->data->window.draw(shieldbar[7]);
			}
			if (shield <= 80 && shield > 70) {
				this->data->window.draw(shieldbar[8]);
			}
			if (shield <= 90 && shield > 80) {
				this->data->window.draw(shieldbar[9]);
			}
			if (shield <= 100 && shield > 90) {
				this->data->window.draw(shieldbar[10]);
			}
		}

	private:
		GameDataRef data;

		Sprite shieldbar[11];
	};

	class Moneybar {
	public:
		Moneybar(GameDataRef data) : data(data) {};

		void Update(int m) {
			
			money.setString(IntToString(m));
			
		}

		void draw() {
			InputHandler input;
			if (input.TabDown) {
				this->data->window.draw(money_name);
				this->data->window.draw(money);
			}
		}

		void init() {
			font.loadFromFile(barfont);
			money.setFont(font);
			money.setFillColor(Color::Red);
			money.setScale(.65, .65);
			money.setPosition(1850,0);
			money_name.setFont(font);
			money_name.setFillColor(Color::Red);
			money_name.setScale(.65, .65);
			money_name.setPosition(1750, 0);
			money_name.setString("Money :");
		}

	public:
		string str;
		Font font;
		Text money;
		Text money_name;
		GameDataRef data;

	};

	class Spellbar {
	public:
		Spellbar(GameDataRef data) : data(data) {};
		void init() {
			font.loadFromFile(barfont);
			l.setFont(font);
			l.setFillColor(Color::Red);
			l.setScale(.65, .65);
			l.setPosition(1850, 40);

			l_n.setFont(font);
			l_n.setFillColor(Color::Red);
			l_n.setScale(.65, .65);
			l_n.setPosition(1750, 40);
			l_n.setString("Lighting :");

			//

			f.setFont(font);
			f.setFillColor(Color::Red);
			f.setScale(.65, .65);
			f.setPosition(1850, 80);

			f_n.setFont(font);
			f_n.setFillColor(Color::Red);
			f_n.setScale(.65, .65);
			f_n.setPosition(1750, 80);
			f_n.setString("Firebolt :");

			//

			r.setFont(font);
			r.setFillColor(Color::Red);
			r.setScale(.65, .65);
			r.setPosition(1850, 120);

			r_n.setFont(font);
			r_n.setFillColor(Color::Red);
			r_n.setScale(.65, .65);
			r_n.setPosition(1750, 120);
			r_n.setString("Revive :");
			
			//

			i.setFont(font);
			i.setFillColor(Color::Red);
			i.setScale(.65, .65);
			i.setPosition(1872, 160);

			i_n.setFont(font);
			i_n.setFillColor(Color::Red);
			i_n.setScale(.65, .65);
			i_n.setPosition(1750, 160);
			i_n.setString("Ice Shardes :");

			//

			e.setFont(font);
			e.setFillColor(Color::Red);
			e.setScale(.65, .65);
			e.setPosition(1865, 200);

			e_n.setFont(font);
			e_n.setFillColor(Color::Red);
			e_n.setScale(.65, .65);
			e_n.setPosition(1750, 200);
			e_n.setString("Electricity :");

		}
		void update(int &l_, int& f_, int &r_, int &i_, int & e_) {
			l.setString(IntToString(l_));
			f.setString(IntToString(f_));
			r.setString(IntToString(r_));
			i.setString(IntToString(i_));
			e.setString(IntToString(e_));

			
		}

		

		void draw() {
			InputHandler input;
			if (input.TabDown) {
				this->data->window.draw(l_n);
				this->data->window.draw(l);
				this->data->window.draw(f_n);
				this->data->window.draw(f);
				this->data->window.draw(r_n);
				this->data->window.draw(r);
				this->data->window.draw(i_n);
				this->data->window.draw(i);
				this->data->window.draw(e_n);
				this->data->window.draw(e);
			}


		}


	private:
		string str;
		GameDataRef data;
		Font font;
		Text l, f, r, i, e, l_n, f_n, r_n, i_n, e_n;


	};
}