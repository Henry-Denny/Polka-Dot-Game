#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML\Graphics.hpp>

class Window
{
public:
    Window();
    Window(const std::string &l_title, sf::Vector2u l_winSize);
    ~Window();

    void Setup(const std::string &l_title, sf::Vector2u l_winSize);

    void BeginDraw();
    void Draw(const sf::Drawable &l_drawable);
    void EndDraw();

    bool IsDone();
    sf::RenderWindow* GetRenderWindow();
    sf::Vector2u GetSize();

    void SetDone(bool l_done);

private:
    bool m_isDone;
    sf::RenderWindow m_window;
};

#endif