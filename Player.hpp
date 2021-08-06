#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>

#include "Dot.hpp"

#define STARTING_SIZE 10
#define SIZE_STEP 2

class Player : public Dot
{
public:
    Player();
    Player(sf::Vector2u l_winSize);
    ~Player();

    void Move(const sf::RenderWindow &l_window);
    void Eat();

    int GetScore();
    sf::CircleShape* GetShape();

private:
    int m_score;
};

#endif