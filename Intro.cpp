#include "Intro.h"
#include "MainMenu.h"
namespace GameEngine {

	IntroState::IntroState(GameDataRef data) : data (data){

	}


	void GameEngine::IntroState::Init()
	{
		
		//loading

		this->data->textures.load("intro001", intro01);
		this->data->textures.load("intro002", intro02);
		this->data->textures.load("intro003", intro03);
		this->data->textures.load("intro004", intro04);
		this->data->textures.load("intro005", intro05);
		this->data->textures.load("intro006", intro06);
		this->data->textures.load("intro007", intro07);
		this->data->textures.load("intro008", intro08);


		// getting

		this->intro[0].setTexture(this->data->textures.get("intro001"));
		this->intro[1].setTexture(this->data->textures.get("intro002"));
		this->intro[2].setTexture(this->data->textures.get("intro003"));
		this->intro[3].setTexture(this->data->textures.get("intro004"));
		this->intro[4].setTexture(this->data->textures.get("intro005"));
		this->intro[5].setTexture(this->data->textures.get("intro006"));
		this->intro[6].setTexture(this->data->textures.get("intro007"));
		this->intro[7].setTexture(this->data->textures.get("intro008"));



		// resizing
		for (int i = 0; i < 8; i++) {
			intro[i].setScale(2, 2);
			intro[i].setPosition(700,300);
		}
		


		
		this->data->fonts.load("Intro Font", intro_font);
		text.setFont(this->data->fonts.get("Intro Font"));
		text.setFillColor(Color::White);
		text.setString("This is Intro");
		text.setPosition(500,500);
		//animation();
		animation();
	}

	void GameEngine::IntroState::HandleInput()
	{

		Event evnt;
		while (this ->data->window.pollEvent(evnt)) {
			if (evnt.key.code == Keyboard::Escape) {
				this->data->window.close();
			}
		}
	}

	void GameEngine::IntroState::Update(float dt)
	{



		if (this->clock.getElapsedTime().asSeconds() > 4.2) {
			
			
			this->data->machine.AddState(StateRef(new MainMenuState(data)), true);
			
		}
		Time deltaTime = seconds(dt);

		this->animator->Update(deltaTime);
		

		

	}

	void GameEngine::IntroState::Draw(float dt)
	{

		this->data->window.clear(Color::Black);
		
		this->animator->Draw();
		
		//this->data->window.draw(this->text);
		this->data->window.display();
	}

}
