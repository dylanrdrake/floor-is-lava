#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include <string>

class CharacterSelectState : public State
{
public:
    CharacterSelectState(GameDataRef data);
    
    void Init();
    
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);
    
private:
    GameDataRef _data;
    
    sf::Sprite _background;
    sf::Sprite _logo;
    sf::Sprite _backButton;
    sf::Sprite _blankButton;
    
    sf::Clock clock;
    
    sf::Sprite _carolLlama;
    sf::Sprite _chipLlama;
    sf::Sprite _zacLlama;
    sf::Sprite _andreaLlama;
    sf::Sprite _dylanLlama;
    sf::Sprite _ianLlama;
    sf::Sprite _gameLlama;
    
    sf::Text startGame;
    sf::Text carol;
    sf::Text andrea;
    sf::Text ian;
    sf::Text dylan;
    sf::Text zac;
    sf::Text chip;
    sf::Font font;
    
    bool spriteClicked = false;
    std::string selectedLlama;
    
};
