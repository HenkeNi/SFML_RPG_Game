#include "Rendering.h"


Rendering::Rendering(const sf::Texture& texture)
	: m_sprite{ texture }
{
}


void Rendering::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}


void Rendering::update(sf::Time dt)
{

}
