#pragma once
#include "Component.h"

#include <vector>
//class Movement;
class Rendering;
// TODO: add enum for Origin { Abs_Centre, Mid_bottom



class Collider : public Component
{
public:
	//Collider(sf::Sprite& body, float friction);
	Collider(Rendering* render, float friction);

	bool checkCollision(Collider& other);

	virtual void update(sf::Time dt) override;

	inline sf::Vector2f getPosition() const { return m_sprite.getPosition(); }
	sf::IntRect getSize() const; 
	//inline sf::Vector2f getHalfSize() const { return static_cast<sf::Vector2f>(m_sprite.getTexture()->getSize()) / 2.f; }

	//Collider getCollider() { return Collider(m_sprite, m_friction); } // return getCollisionBox instead??
	Collider getCollider() { return Collider(m_render, m_friction); } 

	sf::RectangleShape getCollisionBox() const { return m_collisionBox; }
	
	std::tuple<bool, sf::FloatRect> checkIntersect(const sf::Sprite& sprite);
	void handleCollision(Collider& other, sf::FloatRect collision);


	// TEST...
	/*void addComponent(Collider* collider)
	{
		m_colliderComponents.push_back(collider);
	}*/

private:
	//Movement*		   m_movementComponent;
	//sf::RectangleShape m_body;  
	sf::Sprite&		   m_sprite;
	float			   m_friction; // 0 is unmovable - 1 is easiest to move

	sf::RectangleShape m_collisionBox; // Have a Collider pointer in Render??

	static std::vector<Collider*> m_colliderComponents; // MAP INSTEAD <Collider*, GameObjectID>??


	// FOR TEST:.
	Rendering* m_render;



	 // TODO: vector of *Collider pointers?? - all the collider components in the game??
};

