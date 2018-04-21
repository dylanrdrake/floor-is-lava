#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Player.h"
#include "HUD.hpp"
#include <string>

class GameRunState : public State
{
public:
    GameRunState(GameDataRef);
    
    void Init();
    
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);
    static void SetGameSprite(int spriteNumber);
    
private:
    GameDataRef _data;
    
    sf::Sprite _background;
    sf::Sprite _gameLlama;
    sf::Sprite _deathScreenButton;
    sf::Sprite gameSprite;
    
    int livesCount;
    int score;
    
    HUD *hud;
	Player *player;
    
    sf::Clock clock;
    
};

