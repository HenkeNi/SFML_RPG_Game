#include "Rendering.h"

#include "Collider.h"

Rendering::Rendering(const sf::Texture& texture, sf::RenderWindow& target, const sf::Vector2f& startPos)
	: m_sprite{ texture }, m_target{ target }
{
	//m_sprite.setOrigin(sf::Vector2f{ 125.f / 2.f, 140.f / 2.f }); // FIX!!
	m_sprite.setPosition(startPos);

}


void Rendering::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}


void Rendering::draw() const
{
	m_target.draw(m_sprite);

	//// TEST::
	//for (auto itr = m_drawables.begin(); itr != m_drawables.end(); ++itr)
	//	m_target.draw(itr);

	//m_target.draw(*m_shape);
	//m_target.draw()
}


void Rendering::draw(sf::Drawable& drawable) const
{
	m_target.draw(drawable);
}


//void Rendering::addDrawable(const sf::Drawable& drawable)
//{
//	m_drawables.push_back(drawable);
//}
//
//void Rendering::addShape(sf::RectangleShape* shape)
//{
//	m_shape = shape;
//}



void Rendering::update(sf::Time dt)
{
	//draw();
	//m_sprite.rotate(10.f);
}


void Rendering::setTextureRect(const sf::IntRect& rect)
{
	m_partDrawn = rect; // TODO: FIX!! 

	m_sprite.setTextureRect(rect);
}