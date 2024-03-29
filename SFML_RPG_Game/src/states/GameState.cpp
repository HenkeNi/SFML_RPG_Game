#include "GameState.h"
#include "PauseState.h"

#include "../game_object/components/Animation.h"
#include "../game_object/components/Camera.h"
#include "../game_object/components/Collider.h"
#include "../game_object/components/Input.h"
#include "../game_object/components/Movement.h"
#include "../game_object/components/Rendering.h"

#include <memory>
#include <iostream>
#include <string>

GameState::GameState(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: State{ context, keyBindings, stack }//, m_player{ context.m_texturesPtr->getResource("player"), *context.m_windowPtr, sf::Vector2f{ 200.f, 300.f } }
{
	initTileMap();
	initGameObjects();
}


void GameState::draw()
{
	m_context.m_windowPtr->draw(m_tileMap);

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

void GameState::update(sf::Time dt)
{
	updateMousePosition(); // TODO: FIX!!

	//m_player.update(dt);

	for (auto& obj : m_gameObjects)
		obj.update(dt);

}


void GameState::handleEvent(const sf::Event& event)
{
	// m_player.handleEvents(event)
	//m_player.handleAction(m_keyBindingContext.getAction(event.key.code));

	// Escape pressed => pause game
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStackPush(std::make_unique<PauseState>(m_context, m_keyBindingContext, m_stackContext));

}


void GameState::initTileMap()
{
	// TODO: load from file...
	const int level[] =
	{
		0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2,
		0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2,
		0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2,
		0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2,
		0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2,
		0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 1, 1, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 1, 1, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 1, 1, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 1, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 1, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 1, 1, 2,
		0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 1, 1, 2, 2,
		0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 1, 2, 2, 2,
		0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2,
		0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2,
		0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2,
	};

	if (!m_tileMap.load("assets/tilemaps/map.png", sf::Vector2u(64, 64), level, 16, 16));
		return;
	

	
	
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

	GameObject bush;
	bush.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("bush"), *m_context.m_windowPtr, sf::Vector2f{ 420.f, 420.f }));
	m_gameObjects.push_back(std::move(bush));

	GameObject bush1;
	bush1.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("berry_bush"), *m_context.m_windowPtr, sf::Vector2f{ 360.f, 0.f }));
	m_gameObjects.push_back(std::move(bush1));

	GameObject rock;
	rock.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("rock"), *m_context.m_windowPtr, sf::Vector2f{ 120.f, 200.f }));
	rock.addComponent(ComponentType::Collider, std::make_unique<Collider>(rock.getComponent<Rendering*>(ComponentType::Rendering), 0.0f));
	m_gameObjects.push_back(std::move(rock));
	
	GameObject rock2;
	rock2.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("rock"), *m_context.m_windowPtr, sf::Vector2f{ 450.f, 120.f }));
	rock2.addComponent(ComponentType::Collider, std::make_unique<Collider>(rock2.getComponent<Rendering*>(ComponentType::Rendering), 0.0f));
	m_gameObjects.push_back(std::move(rock2));

	GameObject chest;
	chest.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("chest"), *m_context.m_windowPtr, sf::Vector2f{ 270.f, 90.f }));
	//chest.addComponent(ComponentType::Collider,  std::make_unique<Collider>(chest.getComponent<Rendering*>(ComponentType::Rendering)->getSprite(), 1.0f));
	chest.addComponent(ComponentType::Collider, std::make_unique<Collider>(chest.getComponent<Rendering*>(ComponentType::Rendering), 1.0f));
	m_gameObjects.push_back(std::move(chest));


	// PLAYER
	GameObject player;
	player.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(m_context.m_texturesPtr->getResource("player_sheet"), *m_context.m_windowPtr, sf::Vector2f{ 290.f, 220.f }));
	player.addComponent(ComponentType::Animation, std::make_unique<Animation>(player.getComponent<Rendering*>(ComponentType::Rendering), sf::Vector2u{ 3, 6 }));
	player.addComponent(ComponentType::Movement,  std::make_unique<Movement>(player.getComponent<Rendering*>(ComponentType::Rendering), player.getComponent<Animation*>(ComponentType::Animation)));
	player.addComponent(ComponentType::Input,     std::make_unique<Input>(player.getComponent<Movement*>(ComponentType::Movement)));
	//player.addComponent(ComponentType::Collider,  std::make_unique<Collider>(player.getComponent<Rendering*>(ComponentType::Rendering)->getSprite(), 1.0f));
	player.addComponent(ComponentType::Collider, std::make_unique<Collider>(player.getComponent<Rendering*>(ComponentType::Rendering), 1.0f));
	player.addComponent(ComponentType::Camera, std::make_unique<Camera>(*m_context.m_windowPtr, player.getComponent<Movement*>(ComponentType::Movement)));
	m_gameObjects.push_back(std::move(player));
}







