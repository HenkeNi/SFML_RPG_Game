#include "Render.h"



Render::Render(const sf::Texture& texture)
	: m_sprite{ texture }
{
}

Render::Render(Render&& other) noexcept
	: m_sprite{ std::move(other.m_sprite) }
{
}


void Render::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}



void Render::setTexture(const sf::Texture& texture)
{
	m_sprite.setTexture(texture);
}


//Component_esc::Type Render::getType() const 
//{
//	return Component_esc::Type::Render;
//}