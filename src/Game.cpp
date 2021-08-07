#include "Game.hpp"

Game::Game() : m_window("Polka Dot Game", {1600, 1600}), m_mouseVisible(true)
{
    Setup();
}

Game::~Game() {}

void Game::Setup()
{
    sf::Mouse::setPosition(sf::Vector2i(m_window.GetSize().x / 2.0f, m_window.GetSize().y / 2.0f), *m_window.GetRenderWindow());
    Reset();
}

void Game::Reset()
{
    SetMouseVisible(false);
    m_player = Player(m_window.GetSize());
    m_textbox.UpdateTextbox(m_player.GetScore());
    ResetDots();
}

void Game::HandleInput()
{
    // Poll events the ravioli way
    sf::Event event;
    while(m_window.GetRenderWindow()->pollEvent(event))
    {
        switch(event.type)
        {
            case (sf::Event::Closed):
                m_window.SetDone(true);
                break;
            case (sf::Event::KeyPressed):
                if (event.key.code == sf::Keyboard::Escape)
                    ToggleMouseVisibility();
                break;
            case (sf::Event::MouseButtonPressed):
                if (event.mouseButton.button == sf::Mouse::Left)
                    Reset();
                break;
            default:
                break;
        }
    }
}

void Game::Update()
{
    MoveDots();
    if (m_player.IsAlive())
    {
        m_player.Move(*m_window.GetRenderWindow());
        CheckCollisions();
    }
}

void Game::Render()
{
    m_window.BeginDraw();

    // Draw dots
    for (auto itr = m_enemies.begin(); itr != m_enemies.end(); ++itr)
    {
        itr->Render(m_window.GetRenderWindow());
    }
    
    // Draw player
    if (m_player.IsAlive())
        m_player.Render(m_window.GetRenderWindow());

    // Draw score
    if (m_player.IsAlive())
        m_textbox.RenderScore(m_window.GetRenderWindow());
    else
        m_textbox.RenderDeathScreen(m_window.GetRenderWindow(), m_player.GetScore());
    
    m_window.EndDraw();
}

void Game::RestartClock()
{
    m_elapsed = m_clock.restart();
}

Enemy Game::CreateDot()
{
    sf::Color l_colour = k_dotColours[std::rand() % k_dotColours.size()];
    return Enemy(m_window.GetSize(), m_player.GetSize(), l_colour);
}

void Game::ResetDots()
{
    for (auto itr = m_enemies.begin(); itr != m_enemies.end(); ++itr)
    {
        *itr = CreateDot();
    }
}

void Game::MoveDots()
{
    for (auto itr = m_enemies.begin(); itr != m_enemies.end(); ++itr)
    {
        itr->Move(m_elapsed.asSeconds());

        // If the polka dot has left the window, replace it with a new polka dot
        if (!itr->isWithinBounds(m_window.GetSize()))
        {
            *itr = CreateDot();
        }
    }
}

void Game::CheckCollisions()
{
    for (auto itr = m_enemies.begin(); itr != m_enemies.end(); ++itr)
    {
        sf::Vector2f relPosition = m_player.GetPosition() - itr->GetPosition();
        if (std::sqrt((relPosition.x * relPosition.x) + (relPosition.y * relPosition.y)) < m_player.GetSize() + itr->GetSize())
        {
            if (m_player.GetSize() >= itr->GetSize())
            {
                m_player.Eat();
                *itr = CreateDot();
                m_textbox.UpdateTextbox(m_player.GetScore());
            }
            else
            {
                m_player.SetAlive(false);
                SetMouseVisible(true);
            }
        }
    }
}

void Game::SetMouseVisible(bool l_visible)
{
    m_mouseVisible = l_visible;
    m_window.GetRenderWindow()->setMouseCursorVisible(l_visible);
}

void Game::ToggleMouseVisibility()
{
    m_mouseVisible = !m_mouseVisible;
    m_window.GetRenderWindow()->setMouseCursorVisible(m_mouseVisible);
}

Window* Game::GetWindow() { return &m_window; }

