#include "Pause.h"
#include "GameState.h"
#include "MainMenu.h"
void GameEngine::PauseState::Init()
{
	//loading
	this->data->textures.load("pauseback", pausebackground);

	//getting
	this->background_image.setTexture(this->data->textures.get("pauseback"));
	this->background_sound.setBuffer(this->data->soundbuffers.get("Main Menu Background Music"));
	this->changing_options.setBuffer(this->data->soundbuffers.get("Menu Option Changing"));
	this->selection.setBuffer(this->data->soundbuffers.get("Main Menu Selection Music"));
	this->mouse_cursor.setTexture(this->data->textures.get("Cursor"));


	//editing


	background_sound.getLoop();
	background_sound.play();
	background_sound.setVolume(80);

	//options
	text[0].setFont(this->data->fonts.get("Menu Font"));
	text[0].setFillColor(Color::Red);
	text[0].setString("RESUME");
	text[0].setPosition(Vector2f(1920 / 11, 1080 / (main_menu_buttons + 1.75) * 1));
	text[0].setStyle(Text::Bold);
	text[0].setScale(2, 2);


	text[1].setFont(this->data->fonts.get("Menu Font"));
	text[1].setFillColor(Color::White);
	text[1].setString("HOME");
	text[1].setPosition(Vector2f(1920 / 11, 1080 / (main_menu_buttons + 1.75) * 2));
	text[1].setStyle(Text::Bold);
	text[1].setScale(2, 2);


	text[2].setFont(this->data->fonts.get("Menu Font"));
	text[2].setFillColor(Color::White);
	text[2].setString("OPTIONS");
	text[2].setPosition(Vector2f(1920 / 11, 1080 / (main_menu_buttons + 1.75) * 3));
	text[2].setStyle(Text::Bold);
	text[2].setScale(2, 2);



	text[3].setFont(this->data->fonts.get("Menu Font"));
	text[3].setFillColor(Color::White);
	text[3].setString("EXIT");
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

void GameEngine::PauseState::HandleInput()
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
					this->data->machine.RemoveState();
				}
				if (isOptionPressed(text[1])) {
					selection.play();
					this->data->machine.RemoveState();
					this->data->machine.AddState(StateRef(new MainMenuState(data)), true);
				}
				if (isOptionPressed(text[2])) {
					selection.play();
					cout << "Go to High Scores" << endl;
				}
				if (isOptionPressed(text[3])) {
					selection.play();
					this->data->window.close();
				}
			}
		}


		if (evnt.type == evnt.KeyPressed) {
			if (evnt.key.code == Keyboard::Escape) {
				this->data->window.close();
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
					this->data->machine.RemoveState();
					
					break;
				case 1:
					selection.play();
					this->data->machine.RemoveState();
					this->data->machine.AddState(StateRef(new MainMenuState(data)), true);
					break;
				case 2:
					selection.play();
					cout << "Show the high scores" << endl;
					break;
				case 3:
					selection.play();

					cout << "Exit the game" << endl;
					this->data->window.close();
					break;
				}
			}

		}
	}
}

void GameEngine::PauseState::Update(float dt)
{
	this->mouse_cursor.setPosition((Vector2f)Mouse::getPosition(this->data->window));
}

void GameEngine::PauseState::Draw(float dt)
{
	this->data->window.clear();
	this->data->window.draw(this->background_image);



	for (int i = 0; i < main_menu_buttons; i++) {
		this->data->window.draw(this->text[i]);
	}

	this->data->window.draw(mouse_cursor);
	this->data->window.display();
}

void GameEngine::PauseState::MoveUp()
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

void GameEngine::PauseState::MoveDown()
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

void GameEngine::PauseState::Pause()
{
	background_sound.pause();
	this->data->window.setMouseCursorVisible(true);
}

void GameEngine::PauseState::Resume()
{
	background_sound.play();
	this->data->window.setMouseCursorVisible(false);
}

bool GameEngine::PauseState::isOptionPressed(Text& text)
{
	IntRect button_touched(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

	if (button_touched.contains(Mouse::getPosition(this->data->window))) {

		return true;
	}


	return false;
}

void GameEngine::PauseState::CursorTouched(Event& evnt)
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
