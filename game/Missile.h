
#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Missile // Missile class.
{
private:
	Sprite missile; // Missile.
public:

	//====================================
	// Missile: Creates the missile.
	// Parameters:
	// missileTexture: Missile texture.
	// pos: Sets missile position.
	// Return Type: None.
	//====================================

	Missile(Texture &missileTexture, Vector2f pos)
	{
		missile.setPosition(pos);
		missile.setTexture(missileTexture);
	}

	//========================================
	// movemissile: Moves the missile.
	// Parameters:
	// window: window to draw.
	// Return Type: bool (isMissileOffScreen).
	//========================================

	bool moveMissile(RenderWindow &window)
	{
		bool isMissileOffScreen = false; // Detects if missile is off screen.

		window.draw(missile);

		missile.move(0, -5);

		if (missile.getPosition().y < 60)
		{
			isMissileOffScreen = true;
		}

		return isMissileOffScreen; // returns if missile is off screen.
	}
};