#include "Movement.h"
#include "Animation.h"
#include "Rendering.h"

#include <iostream>

Movement::Movement(Rendering* render, Animation* animation)
	: m_renderingComponent{ render }, m_animationComponent{ animation }, m_movementSpeed{ 60.f }
{
}


void Movement::setVelocity(const sf::Vector2f& velocity)
{
	m_velocity = velocity;
}


void Movement::setVelocity(float vx, float vy)
{
	m_velocity.x = vx;
	m_velocity.y = vy;
}



void Movement::accelerate(const sf::Vector2f& velocity)
{
	m_velocity += velocity;
}


void Movement::accelerate(float vx, float vy)
{
	m_velocity.x += vx;
	m_velocity.y += vy;
}


void Movement::decelerate(sf::Time dt)
{
	if (m_velocity.x > 0.f)
		m_velocity.x -= (m_movementSpeed * dt.asSeconds());
	if (m_velocity.x < 0.f)
		m_velocity.x += (m_movementSpeed * dt.asSeconds());

	
	if (m_velocity.y > 0.f)
		m_velocity.y -= (m_movementSpeed * dt.asSeconds());
	if (m_velocity.y < 0.f)
		m_velocity.y += (m_movementSpeed * dt.asSeconds());
}


void Movement::setMovementSpeed(float speed)
{
	m_movementSpeed = speed;
}


void Movement::update(sf::Time dt) 
{
	if (m_renderingComponent)
		m_renderingComponent->getSprite().setPosition(m_velocity * dt.asSeconds() * m_movementSpeed);


	if (m_animationComponent)
	{
		static sf::Vector2f last{ 0.f, 0.f };

		if (last.x > m_velocity.x) // move left?
			//m_animationComponent->
			std::cout << "Moving left!\n"; // TODO: just change spritesheet??
		if (last.x < m_velocity.x) // move right?
			std::cout << "Moving right\n";
		if (last.y > m_velocity.y) // move up?
			std::cout << "Moving up\n";
		if (last.y < m_velocity.y) // move down?
			std::cout << "Moving down\n";


		if (last.x == m_velocity.x && last.y == m_velocity.y) // check if idle left, right?? - need to check if previous larger or smaller
			std::cout << "Idle\n";

		last = m_velocity;
	}

	


		//m_renderingComponent->getSprite().move(m_velocity * dt.asSeconds() * m_movementSpeed);



	//m_velocity.x = 0.f;
	//m_velocity.y = 0.f;

	//decelerate(dt);

	//decelerate();
	// TODO:

	// if (velocity.x > 0.f) moving left
		// set animation to moving left??


	// also check if x is larger than y (if moving left and up for example)...

}






