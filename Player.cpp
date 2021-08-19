#include "Player.h"

rotf::Player::Player(GameDataRef data): data(data)
{

}

void rotf::Player::Init()
{
	// Textures



	//spell

	spells.firebolt.first = 180;
	spells.firebolt.second = 0;
	spells.electricity.first = 500;
	spells.electricity.second = 0;
	spells.iceshards.first = 230;
	spells.iceshards.second = 0;
	spells.lighting.first = 530;
	spells.lighting.second = 0;
	spells.nature.first = 200;
	spells.nature.second = 0;
	spells.revive.first = 700;
	spells.revive.second = 0;
	spells.shadow.first = 180;
	spells.shadow.second = 0;
	spells.wind.first = 80;
	spells.wind.second = 0;




	this->data->soundbuffers.load("Howl Music", dshowl_music);
	this->howl.setBuffer(this->data->soundbuffers.get("Howl Music"));
	
	this->data->soundbuffers.load("Yelp Music", dsyelp_music);
	this->yelp.setBuffer(this->data->soundbuffers.get("Yelp Music"));
	yelp.getLoop();
	yelp.play();
	yelp.setVolume(80);
}

void rotf::Player::Draw()
{

}

void rotf::Player::Update()
{

	
	




}

Vector2f rotf::Player::getpos()
{
	cout << player.getPosition().x << player.getPosition().y << endl;
	return player.getPosition();
}

FloatRect rotf::Player::getbounds()
{
	return player.getGlobalBounds();
}

void rotf::Player::Health()
{
	
	cout << hp << endl;

}



void rotf::Player::HandleInput(Event &evnt)
{
	InputHandler input;

	if (input.DDown || input.ADown || input.LShiftDown|| input.SpaceDown || input.HDown) {
		isidle = false;
	}
	else isidle = true;
	if (input.DDown && !input.LShiftDown) iswalkingfor = true;
	else iswalkingfor = false;
	if (input.ADown && !input.LShiftDown) iswalkingback = true;
	else iswalkingback = false;
	if (input.DDown && input.LShiftDown) isrunningfor = true;
	else isrunningfor = false;
	if (input.SpaceDown) isattacking = true;
	else isattacking = false;
	if (input.HDown) ishowling = true;
	else ishowling = false;




}
