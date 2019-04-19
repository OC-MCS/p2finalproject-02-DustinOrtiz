
//==========================
// Dustin Ortiz
// 19 April 2019
// Programming Assignment #7
// Desciption: Game
//==========================

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 
#include "Screen.h"
#include "Ship.h"
#include "Missiles.h"
#include "AlienArmy.h"

int main()
{
	const int WINDOW_WIDTH = 800; // Window width.
	const int WINDOW_HEIGHT = 600; // window height.

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "***SPACE INVADERS***"); // Window.
	window.setFramerateLimit(60);

	Screen screen; // Screen class.
	Ship ship; // Ship class.
	Missiles missiles; // Missiles class.
	AlienArmy army; // Alien army class.

	screen.createBackground();
	ship.CreateShip(window);
	army.createAlienArmy(window);

	bool start = false; // Start game.
	bool gameover = false; // End game.

	while (window.isOpen())
	{
		Event event; // Detects a user input.

		screen.drawBackground(window);

		if (!start)
		{
			screen.startButton(window, event, start);
		}
		else
		{
			if (gameover)
			{
				screen.gameOverButton(window, event, gameover);
			}
			else
			{
				screen.drawKillsAndLives(window);

				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
					else if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Space)
						{
							Vector2f pos = ship.getShip().getPosition(); // Sets ships position.
							missiles.createMissile(pos);
						}
					}
				}

				ship.shipBoundaries();

				ship.moveShip();

				ship.drawShip(window);

				army.drawAlienArmy(window);

				army.moveAlienArmy(window, screen, gameover);

				missiles.drawMissiles(window);
			}
		}

		window.display();
	} 

	return 0;
}