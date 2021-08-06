#include "Textbox.hpp"

Textbox::Textbox()
{
    m_font.loadFromFile("./res/otomanopee.ttf");
    m_textBox.setFont(m_font);
    m_textBox.setCharacterSize(100);
    m_textBox.setPosition(15, 3);
    m_textBox.setFillColor(sf::Color::White);
    m_textBox.setString("0");
}

Textbox::~Textbox() {}

void Textbox::UpdateTextbox(int l_score)
{
    m_textBox.setString(std::to_string(l_score));
}

void Textbox::Render(sf::RenderWindow *l_window) { l_window->draw(m_textBox); }