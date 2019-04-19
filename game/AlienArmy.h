
#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Alien.h"

class AlienArmy // Alien army class.
{
private:
	list<Alien> army; // List of aliens.
	list<Alien>::iterator iter; // alien iterator.
	Texture alienTexture; // Alien texture.
	int lifeCount = 0; // Life counter.
public:

	//=========================================
	// createAlienArmy: Creates the alien army.
	// Parameters:
	// window: window to draw.
	// Return Type: None.
	//=========================================

	void createAlienArmy(RenderWindow &window)
	{
		if (!alienTexture.loadFromFile("enemy.png"))
		{
			cout << "Unable to load enemy texture!" << endl;
			exit(EXIT_FAILURE);
		}

		float alienX = window.getSize().x / 8.0f; // Alien X axis position.
		float alienY = window.getSize().y / 8.0f; // Alien Y axis position.

		for (int i = 0; i < 10; i++)
		{
			Alien alien(alienTexture, alienX, alienY); // New instance of an Alien.
			army.push_back(alien);
			alienX += 60;
		}
	}

	//=====================================
	// drawAlienArmy: Draws the alien army.
	// Parameters:
	// window: window to draw.
	// Return Type: None.
	//=====================================

	void drawAlienArmy(RenderWindow &window)
	{
		for (iter = army.begin(); iter != army.end(); iter++)
		{
			iter->drawAlien(window);
		}
	}

	//=============================================
	// checkArmyPosition: Checks the army position.
	// Parameters:
	// None.
	// Return Type: None.
	//=============================================

	void checkArmyPosition()
	{
		list<Alien>::iterator check; // Iterator to help check throw the Alien list.

		for (check = army.begin(); check != army.end(); check++)
		{
			check->alienOffScreen(lifeCount);
		}
	}

	//=========================================================================================
	// moveAlienArmy: Moves the alien army and detects if alien reaches ship (Decrements life).
	// Parameters:
	// window: window to draw.
	// screen: Screen to display life decrements.
	// gameover: Detects if all lives are lost then displays Restart button.
	// Return Type: None.
	//=========================================================================================

	void moveAlienArmy(RenderWindow &window, Screen &screen, bool &gameover)
	{
		for (iter = army.begin(); iter != army.end(); iter++)
		{
			iter->moveAlien();

			checkArmyPosition();

			if (lifeCount > 0)
			{
				lifeCount = 0;
				screen.lives();

				if (screen.getLives() == 2)
				{
					resetArmy(window);
				}
				else if (screen.getLives() == 1)
				{
					resetArmy(window);
				}
				else
				{
					resetArmy(window);
					gameover = true;
				}
			}
		}
	}

	//===================================================
	// resetArmy: Resets alien army position back at top.
	// Parameters:
	// window: window to draw.
	// Return Type: None.
	//===================================================

	void resetArmy(RenderWindow &window)
	{
		list<Alien>::iterator reset;

		float alienX = window.getSize().x / 8.0f; // Alien X axis position.
		float alienY = window.getSize().y / 8.0f; // Alien Y axis position.

		for (reset = army.begin(); reset != army.end(); reset++)
		{
			reset->resetAlien(alienX, alienY);
			alienX += 60;
		}
	}
};