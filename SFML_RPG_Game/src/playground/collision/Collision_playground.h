#pragma once
#include <SFML/Graphics.hpp>

namespace collision_playground
{

	class Collider
	{
	public:
		Collider(sf::RectangleShape& body)
			: m_sprite{ body }
		{
		}

		bool checkCollision(const Collider& other, float pushback) // push 0 is not pushable, 1 is light object, 2 heavy
		{
			auto otherPos = other.getPosition();
			auto otherHalfSize = other.getHalfSize();

			auto currentPos = getPosition();
			auto currentHalfSize = getHalfSize();

			float deltaX = otherPos.x - currentPos.x;
			float deltaY = otherPos.y - currentPos.y;

			float intersectX = abs(deltaX) - (otherHalfSize.x + currentHalfSize.x);
			float intersectY = abs(deltaY) - (otherHalfSize.y + currentHalfSize.y);

			if (intersectX < 0.f && intersectY < 0.f)
			{
				pushback = std::min(std::max(pushback, 0.f), 1.f); // force pushback to be from 0.f to 1.f ?? (Clamping)

				// check which intersection is largest (which axis)
				if (intersectX > intersectY)
				{
					if (deltaX > 0.f)
					{
						move(intersectX * (1.f - pushback), 0.f);
						other.move(-intersectX * pushback, 0.f);
					}
					else
					{
						move(-intersectX * (1.f - pushback), 0.f);
						other.move(intersectX * pushback, 0.f);

					}
				}
				else
				{
					if (deltaY > 0.f)
					{
						move(0.f, intersectY * (1.f - pushback));
						other.move(0.f, -intersectY * pushback);
					}
					else
					{
						move(0.f, -intersectY * (1.f - pushback));
						other.move(0.f, intersectY * pushback);
					}
				}

				return true; // collision
			}

			return false; // no collision
		}


		void move(float dx, float dy) const
		{
			m_sprite.move(dx, dy);
		}

		inline sf::Vector2f getPosition() const { return m_sprite.getPosition(); }
		inline sf::Vector2f getHalfSize() const { return m_sprite.getSize() / 2.f; } // return centerpoint instead??

	private:
		sf::RectangleShape& m_sprite;
	};






	class Player
	{
	public:
		Player(const sf::Vector2f& pos, const sf::Vector2f& size)
		{
			m_shape.setPosition(pos);
			m_shape.setFillColor(sf::Color::Red);
			m_shape.setSize(size);
			m_shape.setOrigin(size / 2.f);

		}

		void update(float dt)
		{
			sf::Vector2f movement(0.f, 0.f);
			float speed = 10.f;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				//movement.y -= speed * dt;
				m_shape.move(0, -1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				m_shape.move(0, 1);

				//movement.y += speed * dt;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				m_shape.move(-1, 0);

				//movement.x -= speed * dt;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				//movement.x += speed * dt;
				m_shape.move(1, 0);


			//m_shape.move(movement);
		}

		void draw(sf::RenderWindow& win)
		{
			win.draw(m_shape);
		}

		void setPosition(const sf::Vector2f& pos)
		{
			m_shape.setPosition(pos);
		}
		
		inline sf::Vector2f getPosition() { return m_shape.getPosition(); }

		Collider getCollider() { return Collider(m_shape); }

	private:
		sf::RectangleShape m_shape;
	};


	class Platform
	{
	public:
		Platform(const sf::Vector2f& size, const sf::Vector2f& pos)
		{
			m_shape.setFillColor(sf::Color::Yellow);
			m_shape.setOrigin(size / 2.f);
			m_shape.setSize(size);
			m_shape.setPosition(pos);
		}

		void draw(sf::RenderWindow& win)
		{
			win.draw(m_shape);
		}

		Collider getCollider() { return Collider(m_shape); }

	private:
		sf::RectangleShape m_shape;
	};



	void run();

}

