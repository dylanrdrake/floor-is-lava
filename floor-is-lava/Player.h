// Player.h
//
// This Player class stores all the necessary attributes
// ... of a player object and provides functions for all
// ... player behavior.

#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	// Player's x, y position
	Vector2f position;

	// Player's texture and sprite
	Sprite sprite;
	Texture texture;

	// which direction is the player currently moving in
	bool leftIsPressed;
	bool rightIsPressed;

	// Player's speed in pixels/second
	float speed;

public:
	// constructor
	Player();

	// retreive Player's sprite
	Sprite getSprite();

	// move Player
	void moveLeft();
	void moveRight();

	// Stop Player's movement
	void stopLeft();
	void stopRight();

	// called every frame
	void update(float);
};