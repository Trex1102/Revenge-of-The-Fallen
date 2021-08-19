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
using namespace std;
using namespace sf;
namespace GameEngine {

	inline bool Colliding(double pos1_x, double pos1_y, double pos2_x, double pos2_y) {
		if (pos2_x <= pos1_x && pos2_y <= pos1_y) return true;
		else return false;

	}
}
