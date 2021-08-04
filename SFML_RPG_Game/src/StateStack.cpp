#include "StateStack.h"



void StateStack::update(sf::Time dt)
{
	if (!m_states.empty())
		m_states.top()->update(dt);
	else
		; // TODO: Close window otherwise??
}


void StateStack::draw()
{
	if (!m_states.empty())
		m_states.top()->draw();
}


void StateStack::handleEvent(const sf::Event& event)
{
	if (!m_states.empty())
		m_states.top()->handleEvent(event);
}


void StateStack::pushState(std::unique_ptr<State> state)
{
	m_states.push(std::move(state));
}


void StateStack::popState()
{
	m_states.pop();
}


void StateStack::clearStates()
{
	while (!m_states.empty())
		m_states.pop();
}