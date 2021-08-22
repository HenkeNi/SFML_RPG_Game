#include "Collider.h"
#include "Rendering.h"

#include <iostream>
#include <tuple>

std::vector<Collider*> Collider::m_colliderComponents;


//Collider::Collider(sf::Sprite& body, float friction)
//	: m_sprite{ body }, m_friction{ std::min(std::max(friction, 0.f), 1.f) }
Collider::Collider(Rendering* render, float friction)
	: m_sprite{ render->getSprite() }, m_render{ render }, m_friction{ std::min(std::max(friction, 0.f), 1.f) }
{
	m_collisionBox.setPosition(m_sprite.getPosition());
	m_collisionBox.setOutlineColor(sf::Color::Red);
	m_collisionBox.setOutlineThickness(2.0f);
	m_collisionBox.setSize({100.f, 100.f});

	//m_render->addShape(&m_collisionBox);

	m_colliderComponents.push_back(this);
	//addComponent(this);
	//m_collisionBox.set(sf::Color::Red);
}


bool checkIntersect2(const sf::FloatRect& rect)
{
	//return m_collisonBox.getGlobalBounds().intersects(rect);
	return false;
}

std::tuple<bool, sf::FloatRect> Collider::checkIntersect(const sf::Sprite& sprite)
{
	sf::FloatRect collisionBox = m_render->getSprite().getGlobalBounds();
	//collisionBox.left += 20.f;
	//collisionBox.width -= 20.f;


	sf::FloatRect result;
	bool isColliding = collisionBox.intersects(sprite.getGlobalBounds(), result);

	//std::cout << "Left: " << result.left << "Top: " << result.top << "Width : " << result.width << "Height : " << result.height << "\n";

	return { isColliding, result };
	//return collisionBox.intersects(sprite.getGlobalBounds());
	//return m_render->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds());

	//return m_collisionBox.getGlobalBounds().intersects(shape.getGlobalBounds());
}


void Collider::handleCollision(Collider& other, sf::FloatRect collision)
{
	if (abs(collision.width) < abs(collision.height)) // colliding from side??
	{
		m_sprite.move(-collision.width, 0);
		//	std::cout << "Colliding from side?\n";
		std::cout << other.m_friction << '\n';
	}
	else
		std::cout << "Colliding from top?\n";
}





bool Collider::checkCollision(Collider& other)
{
	// PROBLEM:: Not all objects have movemntcomp
	auto otherPosition{ other.m_sprite.getPosition() }; // TODO: GET CENTER POSITION!!
	
	auto otherSize = other.getSize();
	sf::Vector2f otherHalfSize = { otherSize.width / 2.f, otherSize.height / 2.f };
	//auto otherHalfSize{ other.getHalfSize() };

	auto currentPos{ m_sprite.getPosition() };
	
	auto currentSize = getSize();
	sf::Vector2f currentHalfSize = { currentSize.width / 2.f, currentSize.height / 2.f };
	//auto currentHalfSize{ getHalfSize() };
		
	//std::cout << "OtherSize: " << otherHalfSize.x << ", " << otherHalfSize.y << "... Size: " << currentHalfSize.x << "; " << currentHalfSizes.y << '\n';
	//std::cout << "Size: " << currentHalfSize.x << ", " << currentHalfSize.y << '\n';



	float deltaX = otherPosition.x - currentPos.x;
	float deltaY = otherPosition.y - currentPos.y;

	// OWn function for checking intersection??
	float intersectX = abs(deltaX) - (otherHalfSize.x + currentHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + currentHalfSize.y);


	if (intersectX < 0.f && intersectY < 0.f)
	{
		//pushback = std::min(std::max(pushback, 0.f), 1.f); // force pushback to be from 0.f to 1.f ?? (Clamping)

		// check which intersection is largest (which axis)
		if (intersectX > intersectY)
		{
			if (deltaX > 0.f)
			{
				m_sprite.move(intersectX * (1.f - m_friction), 0.f);
				other.m_sprite.move(-intersectX * m_friction, 0.f);
			}
			else
			{
				m_sprite.move(-intersectX * (1.f - m_friction), 0.f);
				other.m_sprite.move(intersectX * m_friction, 0.f);

			}
		}
		else
		{
			if (deltaY > 0.f)
			{
				m_sprite.move(0.f, intersectY * (1.f - m_friction));
				other.m_sprite.move(0.f, -intersectY * m_friction);
			}
			else
			{
				m_sprite.move(0.f, -intersectY * (1.f - m_friction));
				other.m_sprite.move(0.f, intersectY * m_friction);
			}
		}

		return true; // collision
	}




	return false; // No collision...
}


#include <iostream>
void Collider::update(sf::Time dt)
{
	//if (m_render)
	//	m_render->draw(m_collisionBox);

	for (auto comp : m_colliderComponents)
	{
		if (this == comp)
			continue;

		checkCollision(*comp);
		
		// TODO: CHCEK SPRITE INSTEAD???
		//auto collisionData = checkIntersect(comp->m_render->getSprite());


		//if (std::get<0>(collisionData))
		//	handleCollision(*comp, std::get<1>(collisionData));
		//	//std::cout << "Is colliding " << colliding << '\n';
	}






	//std::cout << "Pos: " << m_collisionBox.getPosition().x << "; " << m_collisionBox.getPosition().y << '\n';
	// TODO: call collision check?? 
}


void Collider::handleEvent(const sf::Event& event)
{

}


sf::IntRect Collider::getSize() const 
{ 
	return m_render->getRectSize(); 
}
