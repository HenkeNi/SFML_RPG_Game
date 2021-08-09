#include "GameObject.h"

#include "components/Movement.h"

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







//void GameObject::draw(sf::RenderTarget& target)
//{
//	target.draw(m_sprite);
//}

void GameObject::update(sf::Time dt)
{
	auto moveComp{ getComponent<Movement*>(ComponentType::Movement) };

	if (!moveComp)
		return;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // TODO: FIX.... (input component???)
		moveComp->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		moveComp->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		moveComp->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		moveComp->move(0.f , 1.f);

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // TODO: FIX....
	//	move(-1.f, 0.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//	move(1.f, 0.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//	move(0.f, -1.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//	move(0.f , 1.f);
}



//void GameObject::setTexture(const sf::Texture& texture)
//{
//	m_sprite.setTexture(texture);
//}