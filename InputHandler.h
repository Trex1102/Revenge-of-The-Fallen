#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
using namespace std;
using namespace sf;
namespace GameEngine {
	class InputHandler {
	public:
		InputHandler() {
			if (Keyboard::isKeyPressed(Keyboard::A)) ADown = true;
			else ADown = false;
			if (Keyboard::isKeyPressed(Keyboard::W)) WDown = true;
			else WDown = false;
			if (Keyboard::isKeyPressed(Keyboard::S)) SDown = true;
			else SDown = false;
			if (Keyboard::isKeyPressed(Keyboard::D)) DDown = true;
			else DDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Space)) SpaceDown = true;
			else SpaceDown = false;
			if (Keyboard::isKeyPressed(Keyboard::LShift)) LShiftDown = true;
			else LShiftDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Num1)) OneDown = true;
			else OneDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Num2)) TwoDown = true;
			else TwoDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Num3)) ThreeDown = true;
			else ThreeDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Num4)) FourDown = true;
			else FourDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Num5)) FiveDown = true;
			else FiveDown = false;
			if (Keyboard::isKeyPressed(Keyboard::LControl)) CltrlDown = true;
			else CltrlDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Up)) UpDown = true;
			else UpDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Down)) DownDown = true;
			else DownDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Right)) RightDown = true;
			else RightDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Left)) LeftDown = true;
			else LeftDown = false;
			if (Keyboard::isKeyPressed(Keyboard::Tab)) TabDown = true;
			else TabDown = false;
			if (Keyboard::isKeyPressed(Keyboard::H)) HDown = true;
			else HDown = false;

			if (Mouse::isButtonPressed(Mouse::Left)) MouseLeftDown = true;
			else MouseLeftDown = false;
			if (Mouse::isButtonPressed(Mouse::Right)) MouseRightDown = true;
			else MouseRightDown = false;
		};
		

	public:
		//bool LeftKeyDown
		bool DDown = false;
		bool ADown = false ;
		bool WDown = false;
		bool SDown = false;
		bool SpaceDown = false;
		bool LShiftDown = false;
		bool OneDown = false;
		bool TwoDown = false;
		bool ThreeDown = false;
		bool FourDown = false;
		bool FiveDown = false;
		bool CltrlDown = false;
		bool UpDown = false;
		bool DownDown = false;
		bool RightDown = false;
		bool LeftDown = false;
		bool TabDown = false;
		bool HDown = false;

		bool MouseLeftDown = false;
		bool MouseRightDown = false;
	};
}