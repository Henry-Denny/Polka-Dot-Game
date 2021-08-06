#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <cmath>
#include <iostream>

#include <SFML\Graphics.hpp>

#include "Dot.hpp"

#define MIN_SPEED 30.0f
#define MAX_SPEED 200.0f
#define MIN_REL_SIZE -8
#define MAX_REL_SIZE 38
#define SIZE_STEP 2

class Enemy : public Dot
{
public:
    Enemy();
    Enemy(sf::Vector2u l_winSize, float l_playerSize, sf::Color l_color);
    Enemy(sf::Vector2f l_startingPos, sf::Vector2f l_increment, float l_speed, float l_size, sf::Color l_color);
    ~Enemy();

    void Create();

    void Move(float deltaTime);

    bool isWithinBounds(sf::Vector2u l_winSize);

private:
    sf::Vector2f m_increment;
    float m_speed;
};

#endif