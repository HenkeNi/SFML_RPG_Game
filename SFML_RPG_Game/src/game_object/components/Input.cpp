#include "Input.h"
#include "Movement.h"


Input::Input(Movement* movement)
	: m_movementComponent{ movement }
{
}


void Input::update(sf::Time dt)
{
	if (!m_movementComponent)
		return;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
		m_movementComponent->accelerate(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_movementComponent->accelerate(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_movementComponent->accelerate(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_movementComponent->accelerate(0.f, 1.f);

}



void Input::handleEvent(const sf::Event& event)
{

}
