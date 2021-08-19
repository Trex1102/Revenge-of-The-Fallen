#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;
namespace GameEngine {
	class Animator {
	public:
		Vector2i start_from;
		Vector2i frame_size;
		Vector2i frame_number;
		int total_frames;
		vector<IntRect> frames;
		bool looping;
		Time Duration;
	public:
		Animator(Sprite& sprite, Vector2i frame_size, Vector2i frame_number,Vector2i start_from, int total_frames, Time Duration, bool looping);
		~Animator(){}
		void AddFrames();
		void Update(Time &dt);
	private:
		Sprite& sprite;
		Time CurrentTime;
	};

}