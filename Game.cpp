#include "Game.h"
#include "Intro.h"
namespace GameEngine {
	GameEngine::Game::Game(int width, int height, string title)
	{
		data->window.create(VideoMode(width, height), title, Style::Default);

		data->machine.AddState(StateRef(new IntroState(this ->data)));

		this->Run();

		
	}

	void GameEngine::Game::Run()
	{
		float newTime, frameTime, interpolation;
		float currentTime = this->clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;
		while (this->data->window.isOpen()) {
			this->data->machine.ProcessStateChanges();
			newTime = this->clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;
			if (frameTime > .03f) frameTime = .03f;

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt) {
				this->data->machine.GetActiveState()->HandleInput();
				this->data->machine.GetActiveState()->Update(dt);
				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}
