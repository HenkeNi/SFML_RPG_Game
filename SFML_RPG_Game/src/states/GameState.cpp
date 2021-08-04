#include "GameState.h"
#include "PauseState.h"

#include <iostream>

GameState::GameState(sf::RenderWindow& window, KeyBinding& keyBindings, ResourceHolder<sf::Font, std::string>& fonts, ResourceHolder<sf::Texture, std::string>& textures, StateStack& stack)
	: State{ window, keyBindings, fonts, textures, stack }
{
}


void GameState::draw()
{
	m_player.draw(m_windowContext);
}

bool GameState::update(sf::Time dt)
{
	m_player.update(dt);
	updateMousePositions(); // TODO: FIX!!
	return false;
}


bool GameState::handleEvent(const sf::Event& event)
{
	
	// m_player.handleEvents(event)
	m_player.handleAction(m_keyBindingContext.getAction(event.key.code));

	// Escape pressed => pause game
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStackPush(std::make_unique<PauseState>(m_windowContext, m_keyBindingContext, m_fontsContext, m_texturesContext, m_stackContext));

	return true; // TODO: CHECK IF NEEDED??
}