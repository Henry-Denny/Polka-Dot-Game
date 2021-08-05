#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>

#define STARTING_SIZE 10
#define SIZE_STEP 2

class Player
{
public:
    Player();
    Player(sf::Vector2u l_winSize);
    ~Player();

    void Move(const sf::RenderWindow &l_window);
    void Eat();

    sf::Vector2f GetPosition();
    sf::Vector2f GetOrigin();
    float GetSize();
    int GetScore();
    sf::CircleShape* GetShape();

private:
    int m_score;

    sf::CircleShape m_shape;
};

#endif