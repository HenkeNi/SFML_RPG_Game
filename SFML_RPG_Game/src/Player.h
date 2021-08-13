#pragma once
#include "game_object/GameObject.h"

#include <SFML/Graphics.hpp>

// TODO: make inherit fomr entity instead??
class Player 
{
public:
	enum class PlayerAction
	{
		MoveUp, MoveDown, MoveLeft, MoveRight, Unkown
	};


public:
	Player(const sf::Texture& texture, sf::RenderWindow& target, const sf::Vector2f& startPos);

	//Player& operator=(const Player& other);

	void draw(sf::RenderTarget& target);
	void update(sf::Time dt);

	void handleAction(PlayerAction action); // TEST!!

private:
	GameObject m_object;
	//Entity m_entity;

	// GameObject m_sprite; // TODO: make entity pointer instead (if using Hero -> Elf, Dwarf, Human ... system)

	// Player contains a Hero* 

};

