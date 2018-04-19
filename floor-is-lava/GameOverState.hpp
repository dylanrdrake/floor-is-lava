#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include <fstream>

class GameOverState : public State
{
public:
    GameOverState(GameDataRef data, int score);
    
    void Init();
    
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);
    
private:
    GameDataRef _data;
    
	sf::Sprite _deadLlama;
	sf::Sprite _background;
    sf::Sprite _playAgainButton;
    
    sf::Text gameOver;
    sf::Text scoreTitle;
    sf::Text scoreNumber;
    sf::Text highScore;
    sf::Text highScoreNumber;
    
    sf::Font font;
    
    int _score;
    int _highScore;
    
};
