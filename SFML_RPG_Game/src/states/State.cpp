#include "State.h"
#include "../StateStack.h"

State::State(sf::RenderWindow& window, KeyBinding& keyBindings, ResourceHolder<sf::Font, std::string>& fonts, ResourceHolder<sf::Texture, std::string>& textures, StateStack& stack)
	: m_windowContext{ window }, m_keyBindingContext{ keyBindings }, m_fontsContext{ fonts }, m_texturesContext{ textures }, m_stackContext{ stack }
{
}


// NEEDED??
void State::updateMousePositions()
{
	m_mousePosScreen = sf::Mouse::getPosition(); // 
	m_mousePosWindow = sf::Mouse::getPosition(m_windowContext);
	m_mousePosView = m_windowContext.mapPixelToCoords(sf::Mouse::getPosition(m_windowContext));
}

void State::requestStackPop()
{
	m_stackContext.popState();
}

void State::requestStackPush(std::unique_ptr<State> state)
{
	m_stackContext.pushState(std::move(state));
}


