#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include <cmath>
#include <iostream>
#include <random>

#include "Enemy.hpp"
#include "Player.hpp"
#include "Textbox.hpp"
#include "Window.hpp"

#define NUM_DOTS 100

static const std::array<sf::Color, 5> k_dotColours = 
{
    sf::Color(153, 57, 85),
    sf::Color(168, 220, 209),
    sf::Color(101, 113, 83), 
    sf::Color(164, 153, 190), 
    sf::Color(241, 127, 41)
};

class Game
{
public:
    Game();
    ~Game();

    void Setup();
    void Reset();
    void HandleInput();
    void Update();
    void Render();
    void RestartClock();

    void ToggleMouseVisibility();

    Enemy CreateDot();
    void ResetDots();
    void MoveDots();
    void CheckCollisions();

    Window* GetWindow();

private:
    Player m_player;
    std::array<Enemy, NUM_DOTS> m_enemies;

    bool m_mouseVisible;
    Window m_window;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    Textbox m_textbox;
};

#endif