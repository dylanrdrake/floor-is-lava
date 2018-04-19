#include "stdafx.h"
#include "HUD.hpp"

#include <string>

HUD::HUD( GameDataRef data) : _data( data )
{
    this->_data->assets.LoadFont("Game Font", GAME_FONT);
    
    //Score Title
    {
        scoreTitle.setFont(_data->assets.GetFont("Game Font"));
        scoreTitle.setString("Your Score");
        scoreTitle.setCharacterSize(22);
        scoreTitle.setFillColor(sf::Color::White);
        scoreTitle.setOutlineColor(sf::Color::Black);
        sf::FloatRect textRect = scoreTitle.getLocalBounds();
        scoreTitle.setOrigin(textRect.left + textRect.width/2.0f,
                            textRect.top  + textRect.height/2.0f);
        scoreTitle.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f - 260));
    }
    
    //User Score
    {
        scoreNumber.setFont(_data->assets.GetFont("Game Font"));
        scoreNumber.setString("0");
        scoreNumber.setCharacterSize(22);
        scoreNumber.setFillColor(sf::Color::White);
        scoreNumber.setOutlineColor(sf::Color::Black);
        sf::FloatRect textRect = scoreNumber.getLocalBounds();
        scoreNumber.setOrigin(textRect.left + textRect.width/2.0f,
                              textRect.top  + textRect.height/2.0f);
        scoreNumber.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f - 240));
    }
    
    //Lives Title
    {
        userLives.setFont(_data->assets.GetFont("Game Font"));
        userLives.setString("Lives");
        userLives.setCharacterSize(22);
        userLives.setFillColor(sf::Color::White);
        userLives.setOutlineColor(sf::Color::Black);
        sf::FloatRect textRect = userLives.getLocalBounds();
        userLives.setOrigin(textRect.left + textRect.width/2.0f,
                            textRect.top  + textRect.height/2.0f);
        userLives.setPosition(sf::Vector2f(SCREEN_WIDTH - 80,SCREEN_HEIGHT/2.0f - 260));
    }
    
    //Number of Lives
    {
        livesNumber.setFont(_data->assets.GetFont("Game Font"));
        livesNumber.setString("0");
        livesNumber.setCharacterSize(22);
        livesNumber.setFillColor(sf::Color::White);
        livesNumber.setOutlineColor(sf::Color::Black);
        sf::FloatRect textRect = livesNumber.getLocalBounds();
        livesNumber.setOrigin(textRect.left + textRect.width/2.0f,
                              textRect.top  + textRect.height/2.0f);
        livesNumber.setPosition(sf::Vector2f(SCREEN_WIDTH - 80,SCREEN_HEIGHT/2.0f - 240));
    }
}

    
void HUD::Draw()
{
    this->_data->window.draw(this->scoreTitle);
    this->_data->window.draw(this->scoreNumber);
    this->_data->window.draw(this->userLives);
    this->_data->window.draw(this->livesNumber);
    
}

void HUD::UpdateHud (int score, int livesCount)
{
    scoreNumber.setString(std::to_string(score));
    livesNumber.setString(std::to_string(livesCount));
    
    if (livesCount < 1)
    {
        this->_data->machine.AddState(StateRef(new GameOverState(_data, score)), true);
    }
}

