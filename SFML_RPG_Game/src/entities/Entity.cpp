#include "Entity.h"

Entity::Entity()
{
	m_shape.setSize( sf::Vector2f(50.f, 50.f) );
	m_shape.setFillColor(sf::Color::Cyan);
}



void Entity::updatePosition(sf::Vector2f pos)
{
	m_shape.move(pos);
}


void Entity::updatePosition(float vx, float vy)
{
	m_shape.move(vx, vy);
}



//void Entity::move(float dt, float dirX, float dirY)
//{
//	m_shape.move(dirX * m_movementSpeed * dt, dirY * m_movementSpeed * dt);
//}

void Entity::move(float dirX, float dirY)
{
	m_shape.move(dirX * m_movementSpeed, dirY * m_movementSpeed);
}




void Entity::draw(sf::RenderTarget& target)
{
	target.draw(m_shape);
}

void Entity::update(sf::Time dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		move(0.f , 1.f);
}
