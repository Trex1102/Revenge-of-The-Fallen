#include "Animator.h"

GameEngine::Animator::Animator(Sprite& sprite, Vector2i frame_size, Vector2i frame_number, Vector2i start_from, int total_frames, Time Duration, bool looping):sprite(sprite), CurrentTime(), Duration(Duration), looping(looping)
{
	this->start_from = start_from;
	this->frame_size = frame_size;
	this->frame_number = frame_number;
	this->total_frames = total_frames;
	AddFrames();
}

void GameEngine::Animator::AddFrames()
{
	Vector2i current_frame = start_from;

	for (int j = 0; j < frame_number.y; j++) {

		current_frame.y += frame_size.y * j;
		for (int i = 0; i < frame_number.x; i++) {
			frames.push_back(IntRect(current_frame.x, current_frame.y, frame_size.x, frame_size.y));
			current_frame.x += frame_size.x;
		}
		current_frame.x = 0;
	}

}

void GameEngine::Animator::Update(Time& dt) {
	CurrentTime += dt;

	float ScaledTime = (CurrentTime.asSeconds() / Duration.asSeconds());
	int current_frame = static_cast<int> (ScaledTime * total_frames);


	if(looping) current_frame %= total_frames;

	else {
		if (current_frame >= total_frames) current_frame = total_frames - 1;
	}


	sprite.setTextureRect(frames[current_frame]);
	
}

