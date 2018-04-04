#include "stdafx.h"
#include "Game.h"
using namespace sf;

// constructor
Game::Game() {
	// get screen resolution and store hey hey hey
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	// create an SFML window and view
	window.create(VideoMode(resolution.x, resolution.y),
		"Game test",
		Style::Fullscreen);

	// Load background image into the texture
	//bkgrdTexture.loadFromFile("background.jpg");

	// Associate the sprite with the texture
	//bkgrdSprite.setTexture(bkgrdTexture);
}


void Game::start() {
	// Timing
	Clock clock;

	// main game loop
	while (window.isOpen()) {
		// Restart the clock and
		// ...save the elapsed time
		Time delta = clock.restart();

		// convert delta to seconds
		float deltaSeconds = delta.asSeconds();

		input();
		update(deltaSeconds);
		render();
	}
}


void Game::input() {
	// Player quits game
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	// Player movement input
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		player.moveLeft();
	}
	else {
		player.stopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		player.moveRight();
	}
	else {
		player.stopRight();
	}

}


// send time passed to all game objects
void Game::update(float seconds) {
	player.update(seconds);
}


// re-draw game every frame
void Game::render() {
	// clear previous frame
	window.clear(Color::Black);

	// draw the background
	//window.draw(bkgrdSprite);
	window.draw(player.getSprite());

	// show what has been drawn
	window.display();
}
