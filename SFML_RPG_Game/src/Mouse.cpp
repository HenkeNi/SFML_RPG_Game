#include "Mouse.h"



sf::Vector2i Mouse::getMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}


bool isMouseOver(const sf::Vector2i& position)
{
	return false;
}
