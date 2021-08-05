#ifndef DOT_HPP
#define DOT_HPP

#include <SFML\Graphics.hpp>

class Dot
{
public:
    Dot();
    ~Dot();

protected:
    virtual void Move(const sf::RenderWindow &l_window) = 0;
    virtual void Move(float deltaTime) = 0;

    sf::CircleShape m_shape;
};

#endif