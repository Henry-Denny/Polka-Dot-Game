#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <string>

#include <SFML\Graphics.hpp>

class Textbox
{
public:
    Textbox();
    ~Textbox();

    void UpdateTextbox(int l_score);
    void Render(sf::RenderWindow *l_window);

private:
    sf::Font m_font;
    sf::Text m_textBox;
};

#endif