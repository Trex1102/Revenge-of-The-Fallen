#include "GameState.h"
#include "Pause.h"
GameEngine::GameState::GameState(GameDataRef data): data(data)
{

}

void GameEngine::GameState::Init()
{

	//player
	player = new Player(this->data);
	player->Init();
	

	//DarkSaber

	darksaber = new DarkSaber(this->data);
	darksaber->init();

	//enemy 

	enemy = new Enemy(this->data);
	enemy->Init();

	//healthbar
	healthbar = new Healthbar(this->data);
	healthbar->init();

	//shieldbar
	shieldbar = new Shieldbar(this->data);
	shieldbar->init();


	//magicbar
	magicbar = new Magicbar(this->data);
	magicbar->init();

	//moneybar
	moneybar = new Moneybar(this->data);
	moneybar->init();

	//spellbar
	spellbar = new Spellbar(this->data);
	spellbar->init();

	//world
	levelone = new LevelOne(this->data);
	levelone->init();

	//bullet
	this->data->textures.load("Bullet Texture" , bullet_texture);

	//cursor change
	//this->data->window.setMouseCursorVisible(false);
	Animation();
	this->enemy->Animation();
}



void GameEngine::GameState::HandleInput()
{
	Event evnt;
	while (this->data->window.pollEvent(evnt)) {
		player->HandleInput(evnt);
		darksaber->HandleInput(evnt);
		levelone->HandleInput(evnt);
		this->enemy->HandleInput(evnt);
		if (evnt.type == evnt.Closed) {
			this->data->window.close();
		}
		if (evnt.type == evnt.KeyPressed) {
			if (evnt.key.code == Keyboard::Escape) {
				
				this->data->machine.AddState(StateRef(new PauseState(data)), false);
			}
			
			
		}
	}
}



void GameEngine::GameState::Update(float dt)
{
	this->UpdateBullets();

	// update player animation
	/*Time deltaTime = seconds(dt);
	player->animator->Update(deltaTime);*/
	Time deltaTime = seconds(dt);
	//this->enemy->Update();
	//this->enemy->Update2();
	this->player->Health();
	this->enemy->BulletUpdate(this->player->hp, this->player->shield);
	this->enemy->Update3(this->player->isattacking, this->player->money);
	this->dswalk->Update(deltaTime);
	this->dsidle->Update(deltaTime);
	this->dsrun->Update(deltaTime);
	this->dsattack->Update(deltaTime);
	this->dshowl->Update(deltaTime);
	this->enemy->animator->Update(deltaTime);
	this->moneybar->Update(this->player->money);
	this->spellbar->update(this->player->spells.lighting.second, this->player->spells.firebolt.second , this->player->spells.revive.second, this->player->spells.iceshards.second , this->player->spells.electricity.second);

}

void GameEngine::GameState::Draw(float dt)
{


	this->data->window.clear(Color::White);
	
	

	this->levelone->draw();

	this->enemy->Draw();
	//darksaber movement
	if (this->player->iswalkingfor || this->player->iswalkingback) {
		this->dswalk->Draw();
	}

	else if (this->player->isidle) this->dsidle->Draw();
	else if (this->player->isrunningfor) this->dsrun->Draw();
	else if (this->player->isattacking) this->dsattack->Draw();
	else if (this->player->ishowling) this->dshowl->Draw();


	//
	this->healthbar->draw(this->player->hp);
	this->shieldbar->draw(this->player->shield);
	this->magicbar->draw(this->player->magicpower);
	this->moneybar->draw();
	this->spellbar->draw();
	//darksaber->draw();
	for (auto bullet : this ->bullets) {
		bullet->Draw();
	}
	this->data->window.display();
}

void GameEngine::GameState::UpdateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets) {
		bullet->Update();
		if (bullet->getbounds().top + bullet->getbounds().height < 0.f) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin()+ counter);
		}
		++counter;
	}
}
