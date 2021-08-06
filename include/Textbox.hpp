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

    sf::Text* GetText();

private:
    sf::Font m_font;
    sf::Text m_textBox;
};

#endif