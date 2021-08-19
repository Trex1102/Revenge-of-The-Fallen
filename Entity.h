#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <map>
#include <iostream>
#include <cassert>
using namespace std;
using namespace sf;
using namespace GameEngine;

namespace rotf {
	class Entity {
	public:
		virtual void Draw() {};
		virtual void HandleInput() {};
		virtual void Update() {};
		virtual void is_Alive() {};
		virtual void on_Destroy() {};
		virtual void impulse() {};
		virtual void Collusion() {};
		virtual void Health() {};
		//virtual void HealthBar() = 0; // separate healthbar header for healths
	};

}