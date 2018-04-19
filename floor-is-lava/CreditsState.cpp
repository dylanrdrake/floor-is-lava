#include "stdafx.h"
#include <sstream>
#include "Definitions.hpp"
#include "CreditsState.hpp"
#include "MainMenuState.hpp"


#include <iostream>

//Default constructor
CreditsState::CreditsState(GameDataRef data) : _data(data)
{
    
}

//Initializes the credits state
void CreditsState::Init()
{
    //Loading sprites for the Credits state
    this->_data->assets.LoadTexture("Credits Background", MAIN_MENU_BACKGROUND);
    this->_data->assets.LoadTexture("Credits Logo", CREDITS_LOGO);
    this->_data->assets.LoadTexture("Back Button", BACK_BUTTON);
    this->_data->assets.LoadTexture("Team OOP", TEAM_OOP);
    
    //Setting the textures to the sprites we loaded.
    _background.setTexture(this->_data->assets.GetTexture("Credits Background"));
    _logo.setTexture(this->_data->assets.GetTexture("Credits Logo"));
    _backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
    _team.setTexture(this->_data->assets.GetTexture("Team OOP"));
    
    //Setting the position of the credits logo
    _logo.setPosition((SCREEN_WIDTH / 2) - (_logo.getGlobalBounds().width / 2), _logo.getGlobalBounds().height / 2 - 110);
    _team.setPosition((60), 20);
    _backButton.setPosition((SCREEN_WIDTH / 2 - 420), SCREEN_HEIGHT / 2 + 218);
}

//Handles the input from the user
void CreditsState::HandleInput()
{
    sf::Event event;
    
    //Handles the exit button at the top of the window
    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }
        
        if (this->_data->input.IsSpriteClicked(this->_backButton, sf::Mouse::Left, this->_data->window))
        {
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
    }
}

void CreditsState::Update(float dt)
{
    
}

void CreditsState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);
    
    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_logo);
    this->_data->window.draw(this->_backButton);
    this->_data->window.draw(this->_team);
    
    this->_data->window.display();
}
