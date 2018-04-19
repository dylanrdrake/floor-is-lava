#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

class OptionsState : public State
{
public:
    OptionsState(GameDataRef data);
    
    void Init();
    
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);
    
private:
    GameDataRef _data;
    
    sf::Sprite _background;
    sf::Sprite _logo;
    sf::Sprite _backButton;
};
