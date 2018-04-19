#include "stdafx.h"

#include "Definitions.hpp"
#include "OptionsState.hpp"
#include "MainMenuState.hpp"

#include <sstream>
#include <iostream>

//Default constructor
OptionsState::OptionsState(GameDataRef data) : _data(data)
{
    
}

//Initializes the credits state
void OptionsState::Init()
{
    //Loading sprites for the Credits state
    this->_data->assets.LoadTexture("Credits Background", MAIN_MENU_BACKGROUND);
    this->_data->assets.LoadTexture("Options Logo", OPTIONS_LOGO);
    this->_data->assets.LoadTexture("Back Button", BACK_BUTTON);
    
    //Setting the textures to the sprites we loaded.
    _background.setTexture(this->_data->assets.GetTexture("Credits Background"));
    _logo.setTexture(this->_data->assets.GetTexture("Options Logo"));
    _backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
    
    //Setting the position of the credits logo
    _logo.setPosition((SCREEN_WIDTH / 2) - (_logo.getGlobalBounds().width / 2), _logo.getGlobalBounds().height / 2 - 110);
    _backButton.setPosition((SCREEN_WIDTH / 2 - 420), SCREEN_HEIGHT / 2 + 218);
}

//Handles the input from the user
void OptionsState::HandleInput()
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

void OptionsState::Update(float dt)
{
    
}

void OptionsState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);
    
    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_logo);
    this->_data->window.draw(this->_backButton);
    
    this->_data->window.display();
}
