#include "GameObject.h"

#include "components/Movement.h"

#include <iostream>

GameObject::GameObject(GameObject&& other) noexcept
	: m_components{ std::move(other.m_components) }
{
	other.m_components.clear(); // NEEDED??
}


//GameObject::GameObject(const sf::Texture& texture, const sf::Vector2f& startPos)
//	: m_sprite{ texture }//, m_position{ startPos }
//{
//	updatePosition(startPos);
//	m_sprite.setScale(0.1f, 0.1f);
//	//m_sprite.setScale(4.f, 4.f);
//	//m_sprite.setTexture(texture);
//
//	//m_shape.setSize( sf::Vector2f(50.f, 50.f) );
//	//m_shape.setFillColor(sf::Color::Cyan);
//}


void GameObject::removeComponent(ComponentType type)
{
	auto found{ m_components.find(type) };

	if (found != m_components.end())
		m_components.erase(found);
}


void GameObject::update(sf::Time dt)
{
	for (const auto& c : m_components)
		c.second->update(dt);
}



