#include "stdafx.h"
#include "Definitions.hpp"

#include "Player.h"
#include "GameOverState.hpp"
#include "GameRunState.hpp"
#include "CharacterSelectState.hpp"

#include <sstream>
#include <iostream>
#include <string>


//Default constructor
GameRunState::GameRunState(GameDataRef data) : _data(data)
{

}

void GameRunState::SetGameSprite(int spriteNumber)
{

}

//Initializes the credits state
void GameRunState::Init()
{
    //Loading sprites for the Credits state
    this->_data->assets.LoadTexture("Play Again Button", PLAY_AGAIN_BUTTON);
    this->_data->assets.LoadFont("Font", GAME_FONT);
    
    hud = new HUD( _data );
	score = 0;
	livesCount = 3;
	hud->UpdateHud(score, livesCount);
	
	_gameLlama.setTexture(this->_data->assets.GetTexture("Game Llama"));
	player = new Player(_gameLlama);
    
    //Setting the textures to the sprites we loaded.
    _deathScreenButton.setTexture(this->_data->assets.GetTexture("Play Again Button"));
    

    
    //Setting the initial position of the player
    //_gameLlama.setPosition(player->getPosition());
    
    //Death Screen Button
    
    _deathScreenButton.setPosition((SCREEN_WIDTH / 2 + 230), SCREEN_HEIGHT / 2 + 140);
    
}

//Handles the input from the user
void GameRunState::HandleInput()
{
    sf::Event event;
    
    //Handles the exit button at the top of the window
    while (this->_data->window.pollEvent(event))
    {
		this->player->input();

        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }
        
        if (this->_data->input.IsSpriteClicked(this->_deathScreenButton, sf::Mouse::Left, this->_data->window))
        {
            score++;
            hud->UpdateHud(score, livesCount);
        }
        
        if (this->_data->input.IsSpriteClicked(this->_deathScreenButton, sf::Mouse::Right, this->_data->window))
        {
            livesCount--;
            hud->UpdateHud(score, livesCount);
        }
    }
}

void GameRunState::Update(float dt)
{
	this->player->update(dt);
    
}

void GameRunState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Black);
    
    this->_data->window.draw(this->_deathScreenButton);
    
	this->_data->window.draw(this->player->getSprite());
    hud->Draw();
    
    this->_data->window.display();
}
