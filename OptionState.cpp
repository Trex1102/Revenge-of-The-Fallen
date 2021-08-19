#include "OptionState.h"
#include "MainMenu.h"
#include "Pause.h"
//#include "GameState.h"
using namespace std;
using namespace sf;
namespace GameEngine {
	OptionState::OptionState(GameDataRef data) : data(data)
	{

	}
	void OptionState::Init()
	{
		// loading
		this->data->textures.load("Main Menu Background", main_menu_background_image);
		this->data->soundbuffers.load("Main Menu Background Music", main_menu_background_music);
		this->data->soundbuffers.load("Menu Option Changing", main_menu_option_changing);
		this->data->soundbuffers.load("Main Menu Selection Music", main_menu_selection_music);
		this->data->fonts.load("Menu Font", main_menu_option_font);
		this->data->textures.load("Cursor", cursor_texture);
		this->data->textures.load("about", opabout);
		this->data->textures.load("howtoplay", ophowtoplay);
		//getting

		this->background_sound.setBuffer(this->data->soundbuffers.get("Main Menu Background Music"));
		this->changing_options.setBuffer(this->data->soundbuffers.get("Menu Option Changing"));
		this->selection.setBuffer(this->data->soundbuffers.get("Main Menu Selection Music"));
		this->background_image.setTexture(this->data->textures.get("Main Menu Background"));
		this->mouse_cursor.setTexture(this->data->textures.get("Cursor"));
		this->about.setTexture(this->data->textures.get("about"));
		this->htp.setTexture(this->data->textures.get("howtoplay"));
		//editing

		background_sound.getLoop();
		background_sound.play();
		background_sound.setVolume(80);

		//options
		text[0].setFont(this->data->fonts.get("Menu Font"));
		text[0].setFillColor(Color::Red);
		text[0].setString("HOW TO PLAY");
		text[0].setPosition(Vector2f(1920 / 11, 1080 / (main_menu_buttons + 1.75) * 1));
		text[0].setStyle(Text::Bold);
		text[0].setScale(2, 2);


		text[1].setFont(this->data->fonts.get("Menu Font"));
		text[1].setFillColor(Color::White);
		text[1].setString("SPELL FACTORY");
		text[1].setPosition(Vector2f(1920 / 11, 1080 / (main_menu_buttons + 1.75) * 2));
		text[1].setStyle(Text::Bold);
		text[1].setScale(2, 2);


		text[2].setFont(this->data->fonts.get("Menu Font"));
		text[2].setFillColor(Color::White);
		text[2].setString("GHOST FACTORY");
		text[2].setPosition(Vector2f(1920 / 11, 1080 / (main_menu_buttons + 1.75) * 3));
		text[2].setStyle(Text::Bold);
		text[2].setScale(2, 2);



		text[3].setFont(this->data->fonts.get("Menu Font"));
		text[3].setFillColor(Color::White);
		text[3].setString("ABOUT GAME");
		text[3].setPosition(Vector2f(1920 / 11, 1080 / (main_menu_buttons + 1.75) * 4));
		text[3].setStyle(Text::Bold);
		text[3].setScale(2, 2);




		selectedItemIndex = 0;
		//options end


		//animation
		animation();

		//animation end

		//mouse cursor

		this->data->window.setMouseCursorVisible(false);

	}


	void OptionState::MoveUp()
	{
		if (selectedItemIndex - 1 >= 0) {
			text[selectedItemIndex].setFillColor(Color::White);
			text[selectedItemIndex].setScale(2, 2);
			selectedItemIndex--;
			text[selectedItemIndex].setFillColor(Color::Red);
			text[selectedItemIndex].setScale(3, 3);
			changing_options.play();
		}
	}
	void OptionState::MoveDown()
	{
		if (selectedItemIndex + 1 < main_menu_buttons) {
			text[selectedItemIndex].setFillColor(Color::White);
			text[selectedItemIndex].setScale(2, 2);
			selectedItemIndex++;
			text[selectedItemIndex].setFillColor(Color::Red);
			text[selectedItemIndex].setScale(3, 3);
			changing_options.play();
		}
	}

	void OptionState::Pause()
	{
		//selection.pause();
		background_sound.pause();
		this->data->window.setMouseCursorVisible(true);
	}

	void OptionState::Resume()
	{
		background_sound.play();
		this->data->window.setMouseCursorVisible(false);
	}

	bool OptionState::isOptionPressed(Text & text)
	{
		IntRect button_touched(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

		if (button_touched.contains(Mouse::getPosition(this->data->window))) {

			return true;
		}


		return false;
	}

	void OptionState::CursorTouched(Event & evnt)
	{


		if (text[0].getGlobalBounds().contains(evnt.mouseMove.x, evnt.mouseMove.y)) {
			text[0].setScale(3, 3);
			text[0].setFillColor(Color::Red);
		}
		if (!(text[0].getGlobalBounds().contains(evnt.mouseMove.x, evnt.mouseMove.y))) {
			text[0].setScale(2, 2);
			text[0].setFillColor(Color::White);
		}
		if (text[1].getGlobalBounds().contains(evnt.mouseMove.x, evnt.mouseMove.y)) {
			text[1].setScale(3, 3);
			text[1].setFillColor(Color::Red);
		}
		if (!(text[1].getGlobalBounds().contains(evnt.mouseMove.x, evnt.mouseMove.y))) {
			text[1].setScale(2, 2);
			text[1].setFillColor(Color::White);
		}
		if (text[2].getGlobalBounds().contains(evnt.mouseMove.x, evnt.mouseMove.y)) {
			text[2].setScale(3, 3);
			text[2].setFillColor(Color::Red);
		}
		if (!(text[2].getGlobalBounds().contains(evnt.mouseMove.x, evnt.mouseMove.y))) {
			text[2].setScale(2, 2);
			text[2].setFillColor(Color::White);
		}
		if (text[3].getGlobalBounds().contains(evnt.mouseMove.x, evnt.mouseMove.y)) {
			text[3].setScale(3, 3);
			text[3].setFillColor(Color::Red);
		}
		if (!(text[3].getGlobalBounds().contains(evnt.mouseMove.x, evnt.mouseMove.y))) {
			text[3].setScale(2, 2);
			text[3].setFillColor(Color::White);
		}


	}


	void OptionState::HandleInput()
	{
		Event evnt;
		while (this->data->window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed) {
				this->data->window.close();
			}

			if (evnt.type == evnt.MouseMoved) {

				CursorTouched(evnt);

			}

			if (evnt.type == evnt.MouseButtonPressed) {
				if (evnt.key.code == Mouse::Left) {
					if (isOptionPressed(text[0])) {
						selection.play();
						ishowtoplay = true;
						isabout = false;
					}

					if (isOptionPressed(text[1])) {
						selection.play();
						cout << "Go to Spell Factory" << endl;
					}
					if (isOptionPressed(text[2])) {
						selection.play();
						cout << "Go to Ghost Factory" << endl;
					}
					if (isOptionPressed(text[3]) ) {
						selection.play();
						isabout = true;
						ishowtoplay = false;
					}
				}
			}


			if (evnt.type == evnt.KeyPressed) {
				if (evnt.key.code == Keyboard::Escape) {
					if (isabout) {
						isabout = false;
					}
					else if (ishowtoplay) {
						ishowtoplay = false;
					}
					else {
						this->data->machine.RemoveState();
					}
				}

				else if (evnt.key.code == Keyboard::S || evnt.key.code == Keyboard::Down) {
					this->MoveDown();
				}
				else if (evnt.key.code == Keyboard::W || evnt.key.code == Keyboard::Up) {
					this->MoveUp();
				}

				else if (evnt.key.code == Keyboard::Enter) {
					switch (this->GetPressedItem())
					{
					case 0:
						selection.play();
						ishowtoplay = true;
						break;
					case 1:
						selection.play();
						cout << "Spell Factory" << endl;
						break;
					case 2:
						selection.play();
						cout << "Ghost Factory" << endl;
						break;
					case 3:
						selection.play();
						isabout = true;
						break;
					}
				}

			}
		}

	}
	void OptionState::Update(float dt)
	{

		Time deltaTime = seconds(dt);
		//animator->Update(deltaTime);

		this->mouse_cursor.setPosition((Vector2f)Mouse::getPosition(this->data->window));






	}
	void OptionState::Draw(float dt)
	{

		this->data->window.clear();

		if (isabout) {
			aboutgame();
		}
		else if (ishowtoplay) {
			howtoplay();
		}



		else {
			this->data->window.draw(this->background_image);



			for (int i = 0; i < main_menu_buttons; i++) {
				this->data->window.draw(this->text[i]);
			}

			this->data->window.draw(mouse_cursor);
		}
		this->data->window.display();
	}

}
