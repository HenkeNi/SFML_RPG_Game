#pragma once
#include "Component.h"

#include <SFML/Graphics.hpp>

class Animation;
class Rendering;

class Movement : public Component
{
public:
	Movement(Rendering* render, Animation* animation = nullptr);
	

	// TODO: rename setPosition and Move??
	void setVelocity(const sf::Vector2f& velocity);
	void setVelocity(float vx, float vy);


	void accelerate(const sf::Vector2f& velocity);
	void accelerate(float vx, float vy);

	void decelerate(sf::Time dt);

	//void setPosition(const sf::Vector2f& pos); // sprite.move is shortcut for setPosition??
	//void setPosition(float vx, float vy);

	//void move(const sf::Vector2f& pos);
	//void move(float vx, float vy);


	// FOR TEST PURPOSE
	inline sf::Vector2f getPosition() const { return m_velocity; }


	void setMovementSpeed(float speed);

	virtual void update(sf::Time dt) override;

private:
	Animation*		m_animationComponent;

	Rendering*		m_renderingComponent; // TODO: use friend class instead??
	sf::Vector2f	m_velocity;
	float			m_movementSpeed;
};

