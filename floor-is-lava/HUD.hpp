#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "Game.hpp"
#include "GameOverState.hpp"

class HUD
{
public:
    HUD( GameDataRef data);
    
    void Draw();
    void UpdateHud (int score, int livesCount);
    
private:
    GameDataRef _data;
    
    sf::Font font;
    
    sf::Text scoreTitle;
    sf::Text scoreNumber;
    sf::Text userLives;
    sf::Text livesNumber;
    
    int livesCount;
    
};
