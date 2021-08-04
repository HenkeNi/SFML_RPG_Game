#pragma once

#include <SFML/Graphics.hpp>

// TODO: inherit from sf::Drawable?? and sf::Transformable
class Entity
{
public:
	Entity();
	virtual ~Entity() = default;

	void updatePosition(sf::Vector2f pos);
	void updatePosition(float vx, float vy);

	//void move(float dt, float dirX, float dirY);
	void move(float dirX, float dirY);

	/*virtual void draw(sf::RenderTarget& target) = 0;
	virtual void update(sf::Time dt) = 0;*/

	virtual void draw(sf::RenderTarget& target);
	virtual void update(sf::Time dt);

protected:
	sf::RectangleShape m_shape;

	sf::Texture m_texture; // Sprite??
	sf::Vector2f m_position, m_size;
	float m_movementSpeed{ 10.f };
};

