
#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Missile.h"

class Missiles // Missiles class.
{
private:
	list<Missile> missiles; // List of missiles.
	list<Missile>::iterator iter; // Missile iterator.
	Texture missileTexture; // Missile texture.
public:

	//====================================
	// createMissile: Creates the missile.
	// Parameters:
	// pos: Sets the missile position.
	// Return Type: None.
	//====================================

	void createMissile(Vector2f pos)
	{
		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}

		missiles.push_back(Missile(missileTexture, pos));
	}

	//==================================
	// drawMissiles: Draws the missiles.
	// Parameters:
	// window: window to draw.
	// Return Type: None.
	//==================================

	void drawMissiles(RenderWindow &window)
	{
		for (iter = missiles.begin(); iter != missiles.end();)
		{
			if (iter->moveMissile(window))
			{
				iter = missiles.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
};