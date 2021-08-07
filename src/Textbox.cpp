#include "Textbox.hpp"

Textbox::Textbox()
{
    m_font.loadFromFile("./res/otomanopee.ttf");
    InitialiseCurrentScoreText();
}

Textbox::~Textbox() {}

void Textbox::InitialiseCurrentScoreText()
{
    m_currentScoreTxt.setFont(m_font);
    m_currentScoreTxt.setFillColor(sf::Color::White);
    m_currentScoreTxt.setCharacterSize(100);
    m_currentScoreTxt.setPosition(15, 3);
    m_currentScoreTxt.setString("0");
}

void Textbox::InitialiseDeathText(sf::Vector2u l_winSize, int l_score)
{
    sf::Text &l_finalScoreTxt = m_deathTxtArr[0];
    l_finalScoreTxt.setString("Score: " + std::to_string(l_score));
    l_finalScoreTxt.setCharacterSize(160);

    sf::Text &l_respawnInfoTxt = m_deathTxtArr[1];
    l_respawnInfoTxt.setString("Click to Play Again...");
    l_respawnInfoTxt.setCharacterSize(80);

    for (auto itr = m_deathTxtArr.begin(); itr != m_deathTxtArr.end(); ++itr)
    {
        itr->setFont(m_font);
        itr->setFillColor(sf::Color::White);
        itr->setOrigin(itr->getLocalBounds().width / 2, 0);
    }

    l_finalScoreTxt.setPosition(l_winSize.x / 2, 400);
    l_respawnInfoTxt.setPosition(l_winSize.x / 2, 800);
}

void Textbox::UpdateTextbox(int l_score)
{
    m_currentScoreTxt.setString(std::to_string(l_score));
}

void Textbox::RenderScore(sf::RenderWindow *l_window) { l_window->draw(m_currentScoreTxt); }
void Textbox::RenderDeathScreen(sf::RenderWindow *l_window, int l_finalScore)
{
    InitialiseDeathText(l_window->getSize(), l_finalScore);
    for (auto itr = m_deathTxtArr.begin(); itr != m_deathTxtArr.end(); ++itr)
    {
        l_window->draw(*itr);
    }
}