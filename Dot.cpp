#include "Dot.hpp"

Dot::Dot() {}
Dot::~Dot() {}

float Dot::GetSize() { return m_shape.getRadius(); }
sf::Vector2f Dot::GetPosition() { return m_shape.getPosition(); }