#include "Background.h"


Background::Background(const sf::Texture& texture, const sf::Vector2f& size, const sf::Vector2f& position)
	: m_backgroundSprite{ texture }
{
	m_backgroundSprite.setScale(size);
	m_backgroundSprite.setPosition(position);
}


void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_backgroundSprite, states);
}


bool Background::isSelectable() const
{
	return false;
}


void Background::handleEvent(const sf::Event& event)
{
}


void Background::update(sf::Vector2f mousePos)
{
}