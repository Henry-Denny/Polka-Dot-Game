#include "Window.hpp"

Window::Window()
{
    Setup("New Window", sf::Vector2u(800, 600));
}

Window::Window(const std::string &l_title, sf::Vector2u l_winSize)
{
    Setup(l_title, l_winSize);
}

Window::~Window()
{
    m_window.close();
}

void Window::Setup(const std::string &l_title, sf::Vector2u l_winSize)
{
    m_isDone = false;
    m_window.create(sf::VideoMode(l_winSize.x, l_winSize.y), l_title);
}

void Window::BeginDraw()
{
    m_window.clear(sf::Color(50, 50, 50));
}

void Window::Draw(const sf::Drawable &l_drawable)
{
    m_window.draw(l_drawable);
}

void Window::EndDraw()
{
    m_window.display();
}

bool Window::IsDone() { return m_isDone; }
sf::RenderWindow* Window::GetRenderWindow() { return &m_window; }
sf::Vector2u Window::GetSize() { return m_window.getSize(); }

void Window::SetDone(bool l_done) { m_isDone = l_done; }