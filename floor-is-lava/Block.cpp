#include "stdafx.h"
#include "Block.h"


Block::Block()
{
	// associate a texture with the sprite
	texture.loadFromFile("block.png");
	sprite.setTexture(texture);

	// set Player's starting position
	position.x = 600;
	position.y = 800;
}


Sprite Block::getSprite() {
	return sprite;
}
