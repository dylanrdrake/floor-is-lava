#include "stdafx.h"
#include "InputManager.hpp"

//This boolean will check to see if the item for out buttons are being clicked.
bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
{
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
        
        if (playButtonRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }
    
    return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
{
    return sf::Mouse::getPosition(window);
}
