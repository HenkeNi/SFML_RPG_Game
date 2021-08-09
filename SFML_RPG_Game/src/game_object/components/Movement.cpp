#include "Movement.h"

#include "Rendering.h"


Movement::Movement(Rendering* render)
	: m_renderingComponent{ render }, m_movementSpeed{ 10.f }
{
}



void Movement::setPosition(const sf::Vector2f& pos)
{
	m_renderingComponent->getSprite().setPosition(pos);
}

void Movement::setPosition(float vx, float vy)
{
	m_renderingComponent->getSprite().setPosition(vx, vy);
}



void Movement::move(const sf::Vector2f& pos)
{
	m_renderingComponent->getSprite().move(pos.x * m_movementSpeed, pos.y * m_movementSpeed);
}

void Movement::move(float vx, float vy)
{
	m_renderingComponent->getSprite().move(vx * m_movementSpeed, vy * m_movementSpeed);
}


void Movement::setMovementSpeed(float speed)
{
	m_movementSpeed = speed;
}


void Movement::update(sf::Time dt) 
{

}