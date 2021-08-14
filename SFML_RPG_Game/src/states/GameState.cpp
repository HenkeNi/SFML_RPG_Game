#include "GameState.h"
#include "PauseState.h"

#include "../game_object/components/Animation.h"
#include "../game_object/components/Input.h"
#include "../game_object/components/Movement.h"
#include "../game_object/components/Rendering.h"

#include <memory>
#include <iostream>

GameState::GameState(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: State{ context, keyBindings, stack }//, m_player{ context.m_texturesPtr->getResource("player"), *context.m_windowPtr, sf::Vector2f{ 200.f, 300.f } }
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
			renderComp->draw();
	}

	//m_player.draw(*m_context.m_windowPtr);


}

bool GameState::update(sf::Time dt)
{
	updateMousePositions(); // TODO: FIX!!

	//m_player.update(dt);

	for (auto& obj : m_gameObjects)
		obj.update(dt);

	return false; // REVOME!=!?
}


bool GameState::handleEvent(const sf::Event& event)
{
	// m_player.handleEvents(event)
	//m_player.handleAction(m_keyBindingContext.getAction(event.key.code));

	// Escape pressed => pause game
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStackPush(std::make_unique<PauseState>(SharedContext{ m_context.m_windowPtr,  m_context.m_texturesPtr, m_context.m_fontsPtr }, m_keyBindingContext, m_stackContext));

	return true; // TODO: CHECK IF NEEDED??
}


void GameState::initGameObjects() // USe a factory instead??
{
	GameObject tree;
	tree.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("tree"), *m_context.m_windowPtr, sf::Vector2f{ 20.f, 20.f }));
	m_gameObjects.push_back(std::move(tree));

	GameObject tree2;
	tree2.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("tree2"), *m_context.m_windowPtr, sf::Vector2f{ 80.f, 450.f }));
	m_gameObjects.push_back(std::move(tree2));

	GameObject tree3;
	tree3.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("tree"), *m_context.m_windowPtr, sf::Vector2f{ 280.f, 350.f }));
	m_gameObjects.push_back(std::move(tree3));

	GameObject tree4;
	tree4.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("tree"), *m_context.m_windowPtr, sf::Vector2f{ 580.f, 325.f }));
	m_gameObjects.push_back(std::move(tree4));

	GameObject tree5;
	tree5.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("tree2"), *m_context.m_windowPtr, sf::Vector2f{ 580.f, 80.f }));
	m_gameObjects.push_back(std::move(tree5));

	GameObject rock;
	rock.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("rock"), *m_context.m_windowPtr, sf::Vector2f{ 120.f, 200.f }));
	m_gameObjects.push_back(std::move(rock));
	
	GameObject rock2;
	rock2.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("rock"), *m_context.m_windowPtr, sf::Vector2f{ 450.f, 120.f }));
	m_gameObjects.push_back(std::move(rock2));


	// PLAYER
	GameObject player;
	player.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("player_sheet"), *m_context.m_windowPtr, sf::Vector2f{ 290.f, 220.f }));
	player.addComponent(ComponentType::Animation, std::make_unique<Animation>(player.getComponent<Rendering*>(ComponentType::Rendering), sf::Vector2u{ 3, 5 }));
	player.addComponent(ComponentType::Movement,  std::make_unique<Movement>(player.getComponent<Rendering*>(ComponentType::Rendering), player.getComponent<Animation*>(ComponentType::Animation)));
	player.addComponent(ComponentType::Input,     std::make_unique<Input>(player.getComponent<Movement*>(ComponentType::Movement)));
	
	m_gameObjects.push_back(std::move(player));



}