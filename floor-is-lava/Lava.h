#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Lava
{
private:
	// Lava x, y position
	Vector2f position;

	// Lava's texture and sprite
	Sprite sprite;
	Texture texture;

	// which direction is the Lava currently moving in
	bool leftIsPressed;
	bool rightIsPressed;

	// move Lava
	bool isRising();

	// Lava's speed in pixels/second
	float riseSpeed;

public:
	// constructor
	Lava();

	// retrieve Lava sprite 
	Sprite getSprite();

	// called every frame
	void update(float);
};

