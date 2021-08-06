#ifndef DOT_HPP
#define DOT_HPP

#include <SFML\Graphics.hpp>

// Base class for Player and Enemy
class Dot
{
public:
    Dot();
    ~Dot();

    void Render(sf::RenderWindow *l_window);
    sf::Vector2f GetPosition();
    float GetSize();

protected:
    sf::CircleShape m_shape;
};

#endif