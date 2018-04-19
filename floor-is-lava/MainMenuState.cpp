#include "stdafx.h"
#include <sstream>
#include "Definitions.hpp"
#include "MainMenuState.hpp"
#include "CharacterSelectState.hpp"
#include "CreditsState.hpp"
#include "OptionsState.hpp"
#include <iostream>

    //Default constructor
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {
        
    }

//Initialized the state, loads all textures and sets their position. 
    void MainMenuState::Init()
    {
        this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND);
        this->_data->assets.LoadTexture("Game Title", GAME_TITLE_LOGO);
        this->_data->assets.LoadTexture("Lava Play Button", LAVA_PLAY_BUTTON);
        this->_data->assets.LoadTexture("Credits Button", CREDITS_BUTTON);
        this->_data->assets.LoadTexture("Options Button", OPTIONS_BUTTON);

        _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
        _title.setTexture(this->_data->assets.GetTexture("Game Title"));
        _playButton.setTexture(this->_data->assets.GetTexture("Lava Play Button"));
        _creditsButton.setTexture(this->_data->assets.GetTexture("Credits Button"));
        _optionsButton.setTexture(this->_data->assets.GetTexture("Options Button"));
        
        //Setting the logo position
        _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2 - 140);
        
        //Setting the play button position
        _playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2 + 180), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2 - 150));
        
        //Setting the menu button position
        _optionsButton.setPosition((SCREEN_WIDTH / 2) - (_optionsButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_optionsButton.getGlobalBounds().height / 2 - 150));
        
        //Setting the credits button position
        _creditsButton.setPosition((SCREEN_WIDTH / 2) - (_creditsButton.getGlobalBounds().width / 2 - 180), (SCREEN_HEIGHT / 2) - (_creditsButton.getGlobalBounds().height / 2 - 150));
        
    }
    
    void MainMenuState::HandleInput()
    {
        sf::Event event;
        
        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            
            if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.AddState(StateRef(new CharacterSelectState(_data)), true);
            }
            
            if (this->_data->input.IsSpriteClicked(this->_creditsButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.AddState(StateRef(new CreditsState(_data)), true);
            }
            
            if (this->_data->input.IsSpriteClicked(this->_optionsButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.AddState(StateRef(new OptionsState(_data)), true);
            }
        }
    }
    
    void MainMenuState::Update(float dt)
    {

    }
    
    void MainMenuState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);
        
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_title);
        this->_data->window.draw(this->_playButton);
        this->_data->window.draw(this->_creditsButton);
        this->_data->window.draw(this->_optionsButton);
        
        this->_data->window.display();
    }

