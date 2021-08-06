#include "Enemy.hpp"

Enemy::Enemy() {}

Enemy::Enemy(sf::Vector2u l_winSize, float l_playerSize, sf::Color l_colour) 
{
    m_shape.setRadius(l_playerSize + MIN_REL_SIZE + (std::rand() % ((MAX_REL_SIZE - MIN_REL_SIZE) / SIZE_STEP + 1)) * SIZE_STEP);
    m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius());
    m_shape.setFillColor(l_colour);

    // Spaghetti, yum
    bool l_vertical = ((double)std::rand() / RAND_MAX) > 0.5f;
    bool l_topLeft = ((double)std::rand() / RAND_MAX) > 0.5f;

    int oppVel = (((double)std::rand() / RAND_MAX) * 2) - 1.0f;
    int absRespVel = std::sqrt(1 - (oppVel * oppVel));
    
    if (l_vertical)
    {
        int verticalPosition = std::rand() % (l_winSize.y + 1);
        if (l_topLeft)
        {
            m_shape.setPosition(-m_shape.getRadius(), verticalPosition);
            m_increment = sf::Vector2f(absRespVel, oppVel);
        }
        else
        {
            m_shape.setPosition(l_winSize.x + m_shape.getRadius(), verticalPosition);
            m_increment = sf::Vector2f(-absRespVel, oppVel);
        }
    }
    else
    {
        int horizontalPosition = std::rand() % (l_winSize.x + 1);
        if (l_topLeft)
        {
            m_shape.setPosition(horizontalPosition, -m_shape.getRadius());
            m_increment = sf::Vector2f(oppVel, absRespVel);
        }
        else
        {
            m_shape.setPosition(horizontalPosition, l_winSize.y + m_shape.getRadius());
            m_increment = sf::Vector2f(oppVel, -absRespVel);
        }
    }

    m_speed = MIN_SPEED + ((double)std::rand() / RAND_MAX) * (MAX_SPEED - MIN_SPEED);
    // std::cout << "Created a dot with position: (" << m_shape.getPosition().x << ", " << m_shape.getPosition().y << ")" << std::endl;
}

Enemy::Enemy(sf::Vector2f l_startingPos, sf::Vector2f l_increment, float l_speed, float l_size, sf::Color l_color) 
    : m_increment(l_increment), m_speed(l_speed)
{
    m_shape.setRadius(l_size);
    m_shape.setPosition(l_startingPos);
    m_shape.setFillColor(l_color);
}

Enemy::~Enemy() 
{
    // std::cout << "Enemy has been destroyed." << std::endl;
}

void Enemy::Move(float deltaTime)
{
    m_shape.move(m_increment * m_speed * deltaTime);
    m_shape.rotate(90 * deltaTime);
}

bool Enemy::isWithinBounds(sf::Vector2u l_winSize)
{
    if (
        m_shape.getPosition().x + m_shape.getRadius() >= 0 &&
        m_shape.getPosition().x - m_shape.getRadius() <= l_winSize.x &&
        m_shape.getPosition().y + m_shape.getRadius() >= 0 &&
        m_shape.getPosition().y - m_shape.getRadius() <= l_winSize.y)
    {
        return true;
    }
    return false;
}

sf::CircleShape* Enemy::GetShape()
{
    return &m_shape;
}