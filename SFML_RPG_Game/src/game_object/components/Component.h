#pragma once

#include <SFML/Graphics.hpp>

class Component
{
public:
	virtual ~Component() = default;

	virtual void update(sf::Time dt) = 0;
	virtual void handleEvent(const sf::Event& event) = 0; // TEST

};

