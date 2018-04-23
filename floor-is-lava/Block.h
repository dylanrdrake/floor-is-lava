#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Block
{
private: 
	// Block's x, y position
	Vector2f position;

	// Block's texture and sprite
	Sprite sprite;
	Texture texture;

public:
	// constructor 
	Block();

	// retreive Block's sprite
	Sprite getSprite();
};

