// Game.h
//
// This main Game class defines a game engine that 
// ... sets up the game window and creates objects
// ... of all necessary classes.
// It tracks the state of the game and the player's
// ... inputs in a main game loop and updates the
// ... game's state every loop.

#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

class Game
{
private:
	// create a window instance
	RenderWindow window;

	// background Sprite and Texture
	//Sprite bkgrdSprite;
	//Texture bkgrdTexture;

	// create a Player object
	Player player;

	// functions called every loop
	void input();
	void update(float);
	void render();

public:
	// constructor
	Game();

	// starts main game loop
	void start();
};