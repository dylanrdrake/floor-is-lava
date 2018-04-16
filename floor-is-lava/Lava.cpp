#include "stdafx.h"
#include "Lava.h"

//constructor
Lava::Lava()
{
	// Lava's speed
	riseSpeed = 100;

	// associate a texture with the sprite
	texture.loadFromFile("lava.png");
	sprite.setTexture(texture);

	// set Lava's starting position
	position.x = 200;
	position.y = 1000;
}

Sprite Lava::getSprite() {
	return sprite;
}

bool Lava::isRising()
{
	leftIsPressed = false;
	rightIsPressed = false;
	return false;
}

// move Lava based on the input this frame,
// ... the time elapsed, and the speed
void Lava::update(float timeDelta) {
	if (rightIsPressed) {
		position.x += riseSpeed * timeDelta;
	}

	if (leftIsPressed) {
		position.x -= riseSpeed * timeDelta;
	}

	// move Player sprite to new position
	sprite.setPosition(position);
}