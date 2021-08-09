#include "GameState.h"
#include "PauseState.h"

#include <iostream>

GameState::GameState(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: State{ context, keyBindings, stack }, m_player{ context.m_texturesPtr->getResource("player_knight") }
{
}


void GameState::draw()
{
	m_player.draw(*m_context.m_windowPtr);
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
		requestStackPush(std::make_unique<PauseState>(SharedContext{ m_context.m_windowPtr,  m_context.m_texturesPtr, m_context.m_fontsPtr }, m_keyBindingContext, m_stackContext));

	return true; // TODO: CHECK IF NEEDED??
}


void GameState::initGameObjects()
{

}