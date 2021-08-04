#pragma once
#include "entities/Entity.h"

#include <SFML/Graphics.hpp>

class Player
{
public:
	enum class PlayerAction
	{
		MoveUp, MoveDown, MoveLeft, MoveRight, Unkown
	};


public:
	void draw(sf::RenderTarget& target);
	void update(sf::Time dt);

	void handleAction(PlayerAction action); // TEST!!

private:
	Entity m_sprite;

};

