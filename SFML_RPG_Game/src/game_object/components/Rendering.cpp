#include "Rendering.h"



Rendering::Rendering(const sf::Texture& texture, sf::RenderWindow& target, const sf::Vector2f& startPos)
	: m_sprite{ texture }, m_target{ target }
{
	m_sprite.setPosition(startPos);
}


void Rendering::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}


void Rendering::draw() const
{
	m_target.draw(m_sprite);
}


void Rendering::update(sf::Time dt)
{
	//draw();
}


void Rendering::setTextureRect(const sf::IntRect& rect)
{
	m_sprite.setTextureRect(rect);
}