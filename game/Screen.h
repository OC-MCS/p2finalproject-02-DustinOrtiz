
#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <string>

class Screen // Screen class.
{
private:
	Sprite screen; // Screen
	Texture starsTexture; // Background texture.
	Font font; // Font.
	int life = 3; // Player life.
	string playerLives = "3"; // Player lives on screen.
	int kill; // Alien kill.
	string alienKills = "0"; // Alien kills on screen.

	//=====================================================
	// die: Displays error  message if font was not loaded.
	// Parameters:
	// msg: Error message.
	// Return Type: None.
	//=====================================================

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

	//==========================
	// loadFont: Loads the font.
	// Parameters:
	// None.
	// Return Type: None.
	//==========================

	void loadFont()
	{
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}
	}

public:

	//==========================================
	// createBackground: Creates the background.
	// Parameters:
	// None.
	// Return Type: None.
	//==========================================

	void createBackground()
	{
		if (!starsTexture.loadFromFile("stars.jpg"))
		{
			cout << "Unable to load stars texture!" << endl;
			exit(EXIT_FAILURE);
		}

		screen.setTexture(starsTexture);
		screen.setScale(1.5, 1.5);
	}

	//==========================================
	// drawBackground: Draws background.
	// Parameters:
	// window: window to draw.
	// Return Type: None.
	//==========================================

	void drawBackground(RenderWindow &window)
	{
		window.draw(screen);
	}

	//===============================================
	// startButton: Creates the start button.
	// Parameters:
	// window: window to draw.
	// event: Detect user input.
	// start: Determines if start button was clicked.
	// Return Type: bool (start).
	//===============================================

	bool startButton(RenderWindow &window, Event &event, bool &start)
	{
		loadFont();

		RectangleShape rectangle; // Rectangle around game name.
		Vector2f recPos(65, 130); // Position of rectangle.
		rectangle.setPosition(recPos);
		rectangle.setOutlineColor(Color::White);
		rectangle.setOutlineThickness(5);
		rectangle.setSize(Vector2f(690, 100));
		rectangle.setFillColor(Color::Transparent);

		Text SI("***SPACE INVADERS***", font, 60); // ***SPACE INVADERS*** text.
		SI.setPosition(80, 140);

		RectangleShape line; // Creates the under main menu.
		Vector2f linePos(275, 320); // Line position.
		line.setPosition(linePos);
		line.setOutlineColor(Color::White);
		line.setOutlineThickness(2);
		line.setSize(Vector2f(250, 0));
		line.setFillColor(Color::White);

		Text mainMenu("Main Menu", font, 50);
		mainMenu.setPosition(275, 250);

		Text P("Press 'P' To Play", font, 50); // Start text.
		P.setPosition(215, 340);

		window.draw(rectangle);
		window.draw(SI);
		window.draw(line);
		window.draw(mainMenu);
		window.draw(P);

		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			start = true;
		}

		return start; // Returns if start button was clicked.
	}

	//==========================================
	// drawKillsAndLives: Draws kills and lives.
	// Parameters:
	// window: window to draw.
	// Return Type: None.
	//==========================================

	void drawKillsAndLives(RenderWindow &window)
	{
		loadFont();

		RectangleShape underLine; // Creates the line underneath the info.
		Vector2f underLinePos(0, 60); // Line position.
		underLine.setPosition(underLinePos);
		underLine.setOutlineColor(Color::White);
		underLine.setOutlineThickness(2);
		underLine.setSize(Vector2f(800, 0));
		underLine.setFillColor(Color::White);

		RectangleShape line1; // Creates the line between the info.
		Vector2f line1Pos(135, 0); // Line position.
		line1.setPosition(line1Pos);
		line1.setOutlineColor(Color::White);
		line1.setOutlineThickness(2);
		line1.setSize(Vector2f(0, 60));
		line1.setFillColor(Color::White);

		RectangleShape line2; // Creates the line between the info.
		Vector2f line2Pos(650, 0); // Line position.
		line2.setPosition(line2Pos);
		line2.setOutlineColor(Color::White);
		line2.setOutlineThickness(2);
		line2.setSize(Vector2f(0, 60));
		line2.setFillColor(Color::White);

		Text SI("***SPACE INVADERS***", font, 30); // ***SPACE INVADERS*** text.
		SI.setPosition(230, 10);

		Text kills("Kills: " + alienKills, font, 30); // Kills text.
		kills.setPosition(20, 10);

		Text lives("Lives: " + playerLives, font, 30); // lives text.
		lives.setPosition(675, 10);

		window.draw(underLine);
		window.draw(line1);
		window.draw(line2);
		window.draw(SI);
		window.draw(kills);
		window.draw(lives);
	}

	//==============================
	// kills: Increments kills text.
	// Parameters:
	// None.
	// Return Type: None.
	//==============================

	void kills()
	{
		kill++;

		if (kill == 1)
		{
			alienKills = '1';
		}
		else if (kill == 2)
		{
			alienKills = '2';
		}
		else if (kill == 3)
		{
			alienKills = '3';
		}
		else if (kill == 4)
		{
			alienKills = '4';
		}
		else if (kill == 5)
		{
			alienKills = '5';
		}
		else if (kill == 6)
		{
			alienKills = '6';
		}
		else if (kill == 7)
		{
			alienKills = '7';
		}
		else if (kill == 8)
		{
			alienKills = '8';
		}
		else if (kill == 9)
		{
			alienKills = '9';
		}
	}

	//=========================
	// lives: Decrements lives.
	// Parameters:
	// None.
	// Return Type: None.
	//=========================

	void lives()
	{
		life--;

		if (life == 2)
		{
			playerLives = '2';
		}
		else
		{
			playerLives = '1';
		}
	}

	//====================================================
	// gameOverButton: Creates the restart button.
	// Parameters:
	// window: window to draw.
	// event: Detects user input.
	// gameover: Determines if restart button was clicked.
	// Return Type: bool (gameover).
	//====================================================

	bool gameOverButton(RenderWindow &window, Event &event, bool &gameover)
	{
		loadFont();

		RectangleShape rectangle; // Rectangle around game over info.
		Vector2f recPos(160, 155); // Position of rectangle.
		rectangle.setPosition(recPos);
		rectangle.setOutlineColor(Color::White);
		rectangle.setOutlineThickness(5);
		rectangle.setSize(Vector2f(490, 250));
		rectangle.setFillColor(Color::Transparent);

		Text GO("***Game Over***", font, 60); // Game over text.
		GO.setPosition(180, 160);

		if (life == 0)
		{
			Text L("You Lose!", font, 50); // Loss text.
			L.setPosition(300, 250);
			window.draw(L);
		}
		else
		{
			Text W("You Win!", font, 50); // Win text.
			W.setPosition(300, 250);
			window.draw(W);
		}

		Text R("Press 'R' To Replay", font, 50); // Restart text.
		R.setPosition(185, 330);

		window.draw(rectangle);
		window.draw(GO);
		window.draw(R);

		if (Keyboard::isKeyPressed(Keyboard::R))
		{
			life = 3;
			playerLives = '3';
			gameover = false;
		}

		return gameover; // Returns if restart button was clicked.
	}

	//========================
	// getLives: Returns life.
	// Parameters:
	// None.
	// Return Type: int (life).
	//=========================

	int getLives()
	{
		return life; // returns a life.
	}

	//=========================
	// getKills: Returns kill.
	// Parameters:
	// None.
	// Return Type: int (kill).
	//=========================

	int getKills()
	{
		return kill; // Returns a kill.
	}
};