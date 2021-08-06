#include "Player.hpp"

Player::Player() {}

Player::Player(sf::Vector2u l_winSize) : m_score(0)
{
    m_shape.setRadius(STARTING_SIZE);
    m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius());
    m_shape.setPosition(l_winSize.x / 2.0f, l_winSize.y / 2.0f);
    m_shape.setFillColor(sf::Color::White);
    m_shape.setOutlineColor(sf::Color::Blue);
}

Player::~Player() {}

void Player::Move(const sf::RenderWindow &l_window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(l_window);
    
    if (mousePos.x < 0 || mousePos.x > l_window.getSize().x || mousePos.y < 0 || mousePos.y > l_window.getSize().y)
        return;

    m_shape.setPosition(sf::Vector2f(sf::Mouse::getPosition(l_window)));
}

void Player::Eat()
{
    ++m_score;
    m_shape.setRadius(GetSize() + SIZE_STEP);
    m_shape.setOrigin(GetSize(), GetSize());
}

int Player::GetScore() { return m_score; }