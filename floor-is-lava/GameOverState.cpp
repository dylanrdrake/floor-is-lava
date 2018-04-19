#include "stdafx.h"
#include "Definitions.hpp"

#include "GameOverState.hpp"
#include "CharacterSelectState.hpp"

#include <sstream>
#include <iostream>
#include <string>

//Default constructor
GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
{
    
}

//Initializes the credits state
void GameOverState::Init()
{
    std::ifstream readFile;
    readFile.open("Resources/Highscore.txt");
    
    
    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            readFile >> _highScore;
        }
    }
    
    readFile.close();
    
    std::ofstream writeFile("Resources/Highscore.txt");
    
    if (writeFile.is_open())
    {
        if (_score > _highScore)
        {
            _highScore = _score;
        }
        
        writeFile << _highScore;
    }
    
    writeFile.close();
    
    //Loading sprites for the Credits state
    this->_data->assets.LoadTexture("Dead Llama", DEAD_LLAMA);
    this->_data->assets.LoadTexture("Play Again Button", PLAY_AGAIN_BUTTON);
    this->_data->assets.LoadFont("Game Font", GAME_FONT);
    
    //Setting the textures to the sprites we loaded.
    _deadLlama.setTexture(this->_data->assets.GetTexture("Dead Llama"));
    _playAgainButton.setTexture(this->_data->assets.GetTexture("Play Again Button"));
    
    //Setting the position of the credits logo
    _deadLlama.setPosition((SCREEN_WIDTH / 2) + (_deadLlama.getGlobalBounds().width / 2), _deadLlama.getGlobalBounds().height / 2 + 50);

    sf::FloatRect textRect = _playAgainButton.getLocalBounds();
    _playAgainButton.setOrigin(textRect.left + textRect.width/2.0f,
                       textRect.top  + textRect.height/2.0f);
    _playAgainButton.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f + 150));
    
    //GAME OVER
    {
        gameOver.setFont(_data->assets.GetFont("Game Font"));
        gameOver.setString("GAME OVER");
        gameOver.setCharacterSize(80);
        gameOver.setFillColor(sf::Color::White);
        gameOver.setOutlineColor(sf::Color::Black);
        
        sf::FloatRect textRect = gameOver.getLocalBounds();
        gameOver.setOrigin(textRect.left + textRect.width/2.0f,
                       textRect.top  + textRect.height/2.0f);
        gameOver.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f - 220));
    }
    
    //Your Score
    {
        scoreTitle.setFont(_data->assets.GetFont("Game Font"));
        scoreTitle.setString("Your Score");
        scoreTitle.setCharacterSize(32);
        scoreTitle.setFillColor(sf::Color::White);
        scoreTitle.setOutlineColor(sf::Color::Black);
        sf::FloatRect textRect = scoreTitle.getLocalBounds();
        scoreTitle.setOrigin(textRect.left + textRect.width/2.0f,
                           textRect.top  + textRect.height/2.0f);
        scoreTitle.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f - 70));
    }
    
    //User Score
    {
        scoreNumber.setFont(_data->assets.GetFont("Game Font"));
        scoreNumber.setString(std::to_string(_score));
        scoreNumber.setCharacterSize(32);
        scoreNumber.setFillColor(sf::Color::White);
        scoreNumber.setOutlineColor(sf::Color::Black);
        sf::FloatRect textRect = scoreNumber.getLocalBounds();
        scoreNumber.setOrigin(textRect.left + textRect.width/2.0f,
                           textRect.top  + textRect.height/2.0f);
        scoreNumber.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f - 45));
    }
    
    //Highest Score
    {
        highScore.setFont(_data->assets.GetFont("Game Font"));
        highScore.setString("Highest Score");
        highScore.setCharacterSize(32);
        highScore.setFillColor(sf::Color::White);
        highScore.setOutlineColor(sf::Color::Black);
        sf::FloatRect textRect = highScore.getLocalBounds();
        highScore.setOrigin(textRect.left + textRect.width/2.0f,
                           textRect.top  + textRect.height/2.0f);
        highScore.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f + 5));
    }
    
    //User Score
    {
        highScoreNumber.setFont(_data->assets.GetFont("Game Font"));
        highScoreNumber.setString(std::to_string(_highScore));
        highScoreNumber.setCharacterSize(32);
        highScoreNumber.setFillColor(sf::Color::White);
        highScoreNumber.setOutlineColor(sf::Color::Black);
        sf::FloatRect textRect = highScoreNumber.getLocalBounds();
        highScoreNumber.setOrigin(textRect.left + textRect.width/2.0f,
                           textRect.top  + textRect.height/2.0f);
        highScoreNumber.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f + 30));
    }
    
}

//Handles the input from the user
void GameOverState::HandleInput()
{
    sf::Event event;
    
    //Handles the exit button at the top of the window
    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }
        
        if (this->_data->input.IsSpriteClicked(this->_playAgainButton, sf::Mouse::Left, this->_data->window))
        {
            this->_data->machine.AddState(StateRef(new CharacterSelectState(_data)), true);
        }
    }
}

void GameOverState::Update(float dt)
{
    
}

void GameOverState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Black);
    
    this->_data->window.draw(this->_playAgainButton);
    this->_data->window.draw(this->gameOver);
    this->_data->window.draw(this->scoreTitle);
    this->_data->window.draw(this->scoreNumber);
    this->_data->window.draw(this->highScore);
    this->_data->window.draw(this->highScoreNumber);
    
    
    this->_data->window.display();
}

