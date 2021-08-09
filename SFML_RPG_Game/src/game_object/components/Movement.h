#pragma once
#include "Component.h"

#include <SFML/Graphics.hpp>

class Rendering;

class Movement : public Component
{
public:
	Movement(Rendering* render);
	
	void setPosition(const sf::Vector2f& pos);
	void setPosition(float vx, float vy);

	void move(const sf::Vector2f& pos);
	void move(float vx, float vy);

	void setMovementSpeed(float speed);

	virtual void update(sf::Time dt) override;

private:
	Rendering*		 m_renderingComponent;
	sf::Vector2f m_velocity;
	float		 m_movementSpeed;
};

