#include "State.h"
#include "../StateStack.h"


State::State(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: m_context{ context }, m_keyBindingContext{ keyBindings }, m_stackContext{ stack }
{
}



// NEEDED??
void State::updateMousePositions()
{
	m_mousePosScreen = sf::Mouse::getPosition(); // 
	m_mousePosWindow = sf::Mouse::getPosition(*m_context.m_windowPtr);
	m_mousePosView = m_context.m_windowPtr->mapPixelToCoords(sf::Mouse::getPosition(*m_context.m_windowPtr));
}

void State::requestStackPop()
{
	m_stackContext.popState();
}

void State::requestStackPush(std::unique_ptr<State> state)
{
	m_stackContext.pushState(std::move(state));
}

void State::requestStateClear()
{
	m_stackContext.clearStates();
}


