#include "PauseState.h"


PauseState::PauseState(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: State{ context, keyBindings, stack }
{
	m_background.setSize(static_cast<sf::Vector2f>(context.m_windowPtr->getSize()));
	m_background.setFillColor(sf::Color::Green);
}


void PauseState::draw()
{
	m_context.m_windowPtr->draw(m_background);
}


bool PauseState::update(sf::Time dt)
{
	return false;
}


bool PauseState::handleEvent(const sf::Event& event)
{
	return false;
}