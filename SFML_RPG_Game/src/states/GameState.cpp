#include "GameState.h"
#include "PauseState.h"

#include "../game_object/components/Rendering.h"
#include "../game_object/components/Movement.h"

#include <memory>
#include <iostream>

GameState::GameState(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: State{ context, keyBindings, stack }, m_player{ context.m_texturesPtr->getResource("player_knight") }
{
	initGameObjects();
}


void GameState::draw()
{

	// TODO: Draw in right order
	for (auto& obj : m_gameObjects)
	{
		//obj.getComponent<Rendering*>(ComponentType::Rendering)->draw(*m_context.m_windowPtr);
		auto renderComp{ obj.getComponent<Rendering*>(ComponentType::Rendering) };

		if (renderComp)
			renderComp->draw(*m_context.m_windowPtr);
	}

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


void GameState::initGameObjects() // USe a factory instead??
{
	GameObject tree;
	tree.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("tree")));
	tree.addComponent(ComponentType::Movement, std::make_unique<Movement>(tree.getComponent<Rendering*>(ComponentType::Rendering)));
	auto treeMoveComp = tree.getComponent<Movement*>(ComponentType::Movement);
	treeMoveComp->setPosition(20.f, 20.f);

	m_gameObjects.push_back(std::move(tree));

}