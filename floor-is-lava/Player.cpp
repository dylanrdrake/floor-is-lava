#include "stdafx.h"
#include "Player.h"

// constructor
Player::Player(Sprite playerSprite) {
	// Player's speed
	speed = 500;

	// associate a texture with the sprite
	sprite = playerSprite;

	// set Player's starting position
	position.x = 500;
	position.y = 500;
}


Sprite Player::getSprite() {
	return sprite;
}

void Player::moveLeft() {
	leftIsPressed = true;
}

void Player::moveRight() {
	rightIsPressed = true;
}

void Player::stopLeft() {
	leftIsPressed = false;
}

void Player::stopRight() {
	rightIsPressed = false;
}

Vector2f Player::getPosition() {
	return position;
}

void Player::input() {
	// Player movement input
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		moveLeft();
	}
	else {
		stopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		moveRight();
	}
	else {
		stopRight();
	}
}

// move Player based on the input this frame,
// ... the time elapsed, and the speed
void Player::update(float timeDelta) {
	if (rightIsPressed) {
		position.x += speed * timeDelta;
	}

	if (leftIsPressed) {
		position.x -= speed * timeDelta;
	}

	// move Player sprite to new position
	sprite.setPosition(position);
}