#include "PauseState.h"


PauseState::PauseState(sf::RenderWindow& window, KeyBinding& keyBindings, ResourceHolder<sf::Font, std::string>& fonts, ResourceHolder<sf::Texture, std::string>& textures, StateStack& stack)
	: State{ window, keyBindings, fonts, textures, stack }
{
	m_background.setSize(static_cast<sf::Vector2f>(window.getSize()));
	m_background.setFillColor(sf::Color::Green);
}


void PauseState::draw()
{
	m_windowContext.draw(m_background);
}


bool PauseState::update(sf::Time dt)
{
	return false;
}


bool PauseState::handleEvent(const sf::Event& event)
{
	return false;
}