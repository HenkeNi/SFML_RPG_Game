#pragma once

#include <SFML/Graphics.hpp>

class Mouse
{
public:
	static sf::Vector2i getMousePosition(sf::RenderWindow& window);
	bool isMouseOver(const sf::Vector2i& position);

private:

};

