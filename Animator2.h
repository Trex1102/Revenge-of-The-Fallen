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

using namespace std;
using namespace sf;

namespace GameEngine {
	class Animator2 {

	public:
		Vector2i start_from;
		Time Duration;
		int total_frames;
		int current_frame = 0;
	public:
		Animator2(GameDataRef data,Sprite *sprites, int total_frames,Time Duration) : CurrentTime(), total_frames(total_frames), data(data), Duration(Duration), sprites(sprites)  {
			
		}

		void Update(Time& dt) {
			CurrentTime += dt;

			float ScaledTime = (CurrentTime.asSeconds() / Duration.asSeconds());
			current_frame = static_cast<int> (ScaledTime * total_frames);

			current_frame %= total_frames;

		}

		void Draw() {
			this->data->window.draw(sprites[current_frame]);
		}

	private:
		
		Time CurrentTime;
		Sprite* sprites;
		GameDataRef data;


	};
}