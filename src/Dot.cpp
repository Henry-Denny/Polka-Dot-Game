#include "Dot.hpp"

Dot::Dot() {}
Dot::~Dot() {}

void Dot::Render(sf::RenderWindow *l_window) { l_window->draw(m_shape); }
float Dot::GetSize() { return m_shape.getRadius(); }
sf::Vector2f Dot::GetPosition() { return m_shape.getPosition(); }