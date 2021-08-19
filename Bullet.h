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
using namespace std;
using namespace sf;
using namespace GameEngine;

namespace rotf {
	class Bullet {
	public:
		Bullet(GameDataRef data,Texture &texture ,Vector2f pos, Vector2f dir, float velocity) : data(data), velocity(velocity)
		{
			this->shape.setTexture(texture);
			this->shape.setPosition(pos);
			direction.x = dir.x;
			direction.y = dir.y;
		}
		

		void Update() {
			shape.move(velocity * direction);
		}

		FloatRect getbounds() {
			return shape.getGlobalBounds();
		}


		void Draw() {
			this->data->window.draw(shape);
		}
		
	private:

		GameDataRef data;
		Sprite shape;
		Vector2f direction;
		float velocity;
		
	};
}