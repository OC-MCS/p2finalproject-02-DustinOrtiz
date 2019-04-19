
#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Ship // Ship class.
{
private:
	Sprite ship; // Ship.
	Texture shipTexture; // Ship texture.
public:
	
	//==============================
	// CreateShip: Creates the ship.
	// Parameters:
	// window: window to draw.
	// Return Type: None.
	//==============================

	void CreateShip(RenderWindow &window)
	{
		if (!shipTexture.loadFromFile("ship.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}

		ship.setTexture(shipTexture);
		float shipX = window.getSize().x / 2.0f; // Ship X axis position.
		float shipY = window.getSize().y / 1.1f; // ship Y axis Position.
		ship.setPosition(shipX, shipY);
	}

	//==========================
	// drawShip: Draws the ship.
	// Parameters:
	// window: window to draw.
	// Return Type: None.
	//==========================

	void drawShip(RenderWindow &window)
	{
		window.draw(ship);
	}

	//=======================================
	// shipBoundaries: Sets ships boundaries.
	// Parameters:
	// None.
	// Return Type: None.
	//=======================================

	void shipBoundaries()
	{
		if (ship.getPosition().x < 0)
		{
			ship.move(5, 0);
		}

		if (ship.getPosition().x + 25 > 800)
		{
			ship.move(-5, 0);
		}
	}

	//==========================
	// moveShip: Moves the ship.
	// Parameters:
	// None.
	// Return Type: None.
	//==========================
	
	void moveShip()
	{
		const float DISTANCE = 5.0f;

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			ship.move(-DISTANCE, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			ship.move(DISTANCE, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			ship.move(-DISTANCE, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			ship.move(DISTANCE, 0);
		}
	}

	//============================
	// getShip: Gets ship.
	// Parameters:
	// None.
	// Return Type: Sprite (ship).
	//============================

	Sprite getShip()
	{
		return ship; // Returns ship.
	}
};