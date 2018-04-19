#pragma once

#include <SFML/Graphics.hpp>

class InputManager
{
public:
    InputManager() {}
    ~InputManager() {}
    
    bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
    bool isPointOverSprite(sf::Vector2f Position, sf::Sprite object);
    
    sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};
