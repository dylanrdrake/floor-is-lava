#include "stdafx.h"
#include <sstream>
#include "Definitions.hpp"
#include "CharacterSelectState.hpp"
#include "MainMenuState.hpp"
#include "GameRunState.hpp"


#include <iostream>

CharacterSelectState::CharacterSelectState(GameDataRef data) : _data(data)
{
    
}

void CharacterSelectState::Init()
{
    this->_data->assets.LoadTexture("Character Select Background", MAIN_MENU_BACKGROUND);
    this->_data->assets.LoadTexture("Character Select Logo", CHAR_SELECT_LOGO);
    this->_data->assets.LoadTexture("Back Button", BACK_BUTTON);
    this->_data->assets.LoadTexture("Blank Button", BLANK_BUTTON);
    
    this->_data->assets.LoadTexture("Carol Llama", CAROL_LLAMA);
    this->_data->assets.LoadTexture("Andrea Llama", ANDREA_LLAMA);
    this->_data->assets.LoadTexture("Ian Llama", IAN_LLAMA);
    this->_data->assets.LoadTexture("Dylan Llama", DYLAN_LLAMA);
    this->_data->assets.LoadTexture("Zac Llama", ZAC_LLAMA);
    this->_data->assets.LoadTexture("Chip Llama", CHIP_LLAMA);
    
    
    _background.setTexture(this->_data->assets.GetTexture("Character Select Background"));
    _logo.setTexture(this->_data->assets.GetTexture("Character Select Logo"));
    _backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
    _blankButton.setTexture(this->_data->assets.GetTexture("Blank Button"));
    
    _carolLlama.setTexture(this->_data->assets.GetTexture("Carol Llama"));
    _andreaLlama.setTexture(this->_data->assets.GetTexture("Andrea Llama"));
    _ianLlama.setTexture(this->_data->assets.GetTexture("Ian Llama"));
    _dylanLlama.setTexture(this->_data->assets.GetTexture("Dylan Llama"));
    _zacLlama.setTexture(this->_data->assets.GetTexture("Zac Llama"));
    _chipLlama.setTexture(this->_data->assets.GetTexture("Chip Llama"));
    

    //Loading the game font.
    if (!font.loadFromFile(GAME_FONT))
    {
        std::cout << "Charatcer Selection Font Halted." << std::endl;
        std::exit(-1);
    }
    
    //Start game text that overlays the blank button.
    {
        startGame.setFont(font);
        startGame.setString("Start");
        startGame.setCharacterSize(40);
        startGame.setFillColor(sf::Color::Color(128,128,128,255));
        startGame.setOutlineColor(sf::Color::Black);
        
        sf::FloatRect textRect = startGame.getLocalBounds();
        startGame.setOrigin(textRect.left + textRect.width/2.0f,
                           textRect.top  + textRect.height/2.0f);
        startGame.setPosition((SCREEN_WIDTH / 2 + 310), SCREEN_HEIGHT / 2 + 183);
    }
    
    //Name for Carol Llama that is under the lama.
    {
        carol.setFont(font);
        carol.setString("Carol");
        carol.setCharacterSize(30);
        carol.setFillColor(sf::Color::White);
        carol.setOutlineColor(sf::Color::Black);
        
        sf::FloatRect textRect = carol.getLocalBounds();
        carol.setOrigin(textRect.left + textRect.width/2.0f,
                            textRect.top  + textRect.height/2.0f);
        carol.setPosition((SCREEN_WIDTH / 2 - 290), SCREEN_HEIGHT / 2 + 60);
    }
    
    //Name for Andrea Llama that is under the lama.
    {
        andrea.setFont(font);
        andrea.setString("Andrea");
        andrea.setCharacterSize(30);
        andrea.setFillColor(sf::Color::White);
        andrea.setOutlineColor(sf::Color::Black);
        
        sf::FloatRect textRect = andrea.getLocalBounds();
        andrea.setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
        andrea.setPosition((SCREEN_WIDTH / 2 - 170), SCREEN_HEIGHT / 2 + 60);
    }
    
    //Name for Ian Llama that is under the lama.
    {
        ian.setFont(font);
        ian.setString("Ian");
        ian.setCharacterSize(30);
        ian.setFillColor(sf::Color::White);
        ian.setOutlineColor(sf::Color::Black);
        
        sf::FloatRect textRect = ian.getLocalBounds();
        ian.setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
        ian.setPosition((SCREEN_WIDTH / 2 - 50), SCREEN_HEIGHT / 2 + 60);
    }
    
    //Name for Dylan Llama that is under the lama.
    {
        dylan.setFont(font);
        dylan.setString("Dylan");
        dylan.setCharacterSize(30);
        dylan.setFillColor(sf::Color::White);
        dylan.setOutlineColor(sf::Color::Black);
        
        sf::FloatRect textRect = dylan.getLocalBounds();
        dylan.setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
        dylan.setPosition((SCREEN_WIDTH / 2 + 70), SCREEN_HEIGHT / 2 + 60);
    }
    
    //Name for Zac Llama that is under the lama.
    {
        zac.setFont(font);
        zac.setString("Zac");
        zac.setCharacterSize(30);
        zac.setFillColor(sf::Color::White);
        zac.setOutlineColor(sf::Color::Black);
        
        sf::FloatRect textRect = zac.getLocalBounds();
        zac.setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
        zac.setPosition((SCREEN_WIDTH / 2 + 190), SCREEN_HEIGHT / 2 + 60);
    }
    
    //Name for Chip Llama that is under the lama.
    {
        chip.setFont(font);
        chip.setString("Chip");
        chip.setCharacterSize(30);
        chip.setFillColor(sf::Color::White);
        chip.setOutlineColor(sf::Color::Black);
        
        sf::FloatRect textRect = chip.getLocalBounds();
        chip.setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
        chip.setPosition((SCREEN_WIDTH / 2 + 310), SCREEN_HEIGHT / 2 + 60);
    }
    
    _logo.setPosition((SCREEN_WIDTH / 2) - (_logo.getGlobalBounds().width / 2), _logo.getGlobalBounds().height / 2 - 110);
    
    _backButton.setPosition((SCREEN_WIDTH / 2 - 420), SCREEN_HEIGHT / 2 + 218);
    
    _blankButton.setPosition((SCREEN_WIDTH / 2 + 230), SCREEN_HEIGHT / 2 + 140);
    
    //Setting the position of the characters for selection
    _carolLlama.setPosition((SCREEN_WIDTH / 2 - 320), SCREEN_HEIGHT / 2 - 18);
    _andreaLlama.setPosition((SCREEN_WIDTH / 2 - 200), SCREEN_HEIGHT / 2 - 18);
    _ianLlama.setPosition((SCREEN_WIDTH / 2 - 80), SCREEN_HEIGHT / 2 - 18);
    _dylanLlama.setPosition((SCREEN_WIDTH / 2 + 40), SCREEN_HEIGHT / 2 - 18);
    _zacLlama.setPosition((SCREEN_WIDTH / 2 + 160), SCREEN_HEIGHT / 2 - 18);
    _chipLlama.setPosition((SCREEN_WIDTH / 2 + 280), SCREEN_HEIGHT / 2 - 18);
}

void CharacterSelectState::HandleInput()
{
    sf::Event event;
    
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
        
        if (this->_data->input.IsSpriteClicked(this->_carolLlama, sf::Mouse::Left, this->_data->window))
        {
            startGame.setFillColor(sf::Color::Green);
            spriteClicked = true;
            selectedLlama = CAROL_LLAMA;
        }
        
        if (this->_data->input.IsSpriteClicked(this->_andreaLlama, sf::Mouse::Left, this->_data->window))
        {
            startGame.setFillColor(sf::Color::Red);
            spriteClicked = true;
			selectedLlama = ANDREA_LLAMA;
        }
        
        if (this->_data->input.IsSpriteClicked(this->_ianLlama, sf::Mouse::Left, this->_data->window))
        {
            startGame.setFillColor(sf::Color::Blue);
            spriteClicked = true;
			selectedLlama = IAN_LLAMA;
        }
        
        if (this->_data->input.IsSpriteClicked(this->_dylanLlama, sf::Mouse::Left, this->_data->window))
        {
            startGame.setFillColor(sf::Color::Yellow);
            spriteClicked = true;
			selectedLlama = DYLAN_LLAMA;
        }
        
        if (this->_data->input.IsSpriteClicked(this->_zacLlama, sf::Mouse::Left, this->_data->window))
        {
            startGame.setFillColor(sf::Color::Magenta);
            spriteClicked = true;
			selectedLlama = ZAC_LLAMA;
        }
        
        if (this->_data->input.IsSpriteClicked(this->_chipLlama, sf::Mouse::Left, this->_data->window))
        {
            startGame.setFillColor(sf::Color::Cyan);
            spriteClicked = true;
			selectedLlama = CHIP_LLAMA;
        }
        
        if(spriteClicked == true)
        {
            if (this->_data->input.IsSpriteClicked(this->_blankButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.AddState(StateRef(new GameRunState(_data, selectedLlama)), true);
            }
        }
    }
}

void CharacterSelectState::Update(float dt)
{
    
}

void CharacterSelectState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);
    
    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_logo);
    this->_data->window.draw(this->_backButton);
    this->_data->window.draw(this->_blankButton);
    this->_data->window.draw(this->startGame);
    
    this->_data->window.draw(this->_carolLlama);
    this->_data->window.draw(this->_andreaLlama);
    this->_data->window.draw(this->_ianLlama);
    this->_data->window.draw(this->_dylanLlama);
    this->_data->window.draw(this->_zacLlama);
    this->_data->window.draw(this->_chipLlama);
    
    this->_data->window.draw(this->carol);
    this->_data->window.draw(this->andrea);
    this->_data->window.draw(this->ian);
    this->_data->window.draw(this->dylan);
    this->_data->window.draw(this->zac);
    this->_data->window.draw(this->chip);
    
    this->_data->window.display();
}


