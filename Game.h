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
using namespace std;
using namespace sf;
namespace GameEngine {
	struct GameData {
		StateMachine machine;
		RenderWindow window;
		AssetManager <Texture> textures;
		AssetManager <Font> fonts;
		AssetManager <SoundBuffer> soundbuffers;
	};

	typedef shared_ptr<GameData> GameDataRef;

	class Game {
	public:
		Game(int width, int height, string title);
	private:
		const float dt = 0.01; 
		Clock clock;
		Clock get_elapsed_time;
		GameDataRef data = make_shared<GameData>();
		void Run();

	};
}