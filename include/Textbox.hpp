#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <array>
#include <string>

#include <SFML\Graphics.hpp>

class Textbox
{
public:
    Textbox();
    ~Textbox();

    void InitialiseCurrentScoreText();
    void InitialiseDeathText(sf::Vector2u l_winSize, int l_score);
    void UpdateTextbox(int l_score);
    void RenderScore(sf::RenderWindow *l_window);
    void RenderDeathScreen(sf::RenderWindow *l_window, int l_finalScore);

private:
    sf::Font m_font;
    sf::Text m_currentScoreTxt;
    std::array<sf::Text, 2> m_deathTxtArr;
};

#endif