
#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Alien // Alien class.
{
private:
	Sprite alien; // Alien.
	float alienX; // Alien X axis.
	float alienY; // Alien Y axis
public:

	//==================================
	// Alien: Sets alien.
	// Parameters:
	// alienTexture: sets alien texture.
	// axisX: X axis position.
	// axisY: Y axis position
	// Return Type: None.
	//==================================

	Alien(Texture &alienTexture, float axisX, float axisY)
	{
		alien.setTexture(alienTexture);
		alienX = axisX;
		alienY = axisY;
		alien.setPosition(alienX, alienY);
	}

	//============================
	// drawAlien: Draws the alien.
	// Parameters:
	// window: window to draw.
	// Return Type: None.
	//============================

	void drawAlien(RenderWindow &window)
	{
		window.draw(alien);
	}

	//============================
	// moveAlien: Moves the alien.
	// Parameters:
	// None.
	// Return Type: None.
	//============================

	void moveAlien()
	{
		alien.move(0, 0.3f);
	}

	//==================================================
	// alienOffScreen: Detects if the alien is off screen.
	// Parameters:
	// lifeCount: Increments life count.
	// Return Type: None.
	//==================================================

	void alienOffScreen(int &lifeCount)
	{
		if (alien.getPosition().y > 500)
		{
			lifeCount++;
		}
	}

	//====================================================
	// resetAlien: Resets the aliens position back at top.
	// Parameters:
	// axisX: X axis position.
	// axisY: Y axis position.
	// Return Type: None.
	//====================================================

	void resetAlien(float axisX, float axisY)
	{
		alienX = axisX;
		alienY = axisY;
		alien.setPosition(alienX, alienY);
	}
};