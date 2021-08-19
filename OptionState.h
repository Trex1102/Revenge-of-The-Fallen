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
using namespace std;
using namespace sf;

namespace GameEngine {
	class OptionState : public State {

	public:
		OptionState(GameDataRef data);
		~OptionState() {};
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		void animation() {
			animator = new Animator(this->menu_animation, Vector2i(147, 96), Vector2i(11, 1), Vector2i(0, 0), 11, seconds(1.1), true);

		}
		void MoveUp();
		void MoveDown();
		int GetPressedItem() { return selectedItemIndex; }
		void Pause();
		void Resume();
		bool isOptionPressed(Text& text);
		void CursorTouched(Event& evnt);

		void aboutgame() {
			this->data->window.draw(about);
		}

		void howtoplay() {
			this->data->window.draw(htp);
		}
	private:
		GameDataRef data;
		Clock clock;
		Sprite background_image;
		Sprite mouse_cursor;
		Sprite about;
		Sprite htp;


		bool isabout;
		bool ishowtoplay;
		Sound background_sound;
		Sound changing_options;
		Sound selection;
		Text text[main_menu_buttons];
		Animator* animator;
		int selectedItemIndex;
		Font font;
		Sprite menu_animation;
	};
}