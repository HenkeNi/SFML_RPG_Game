#pragma once

#include "components/Component.h"
#include "components/ComponentTypes.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <unordered_map>

// GameObject or Entity
class GameObject
{
public:
	virtual ~GameObject() = default;

	template <typename T>
	T getComponent(ComponentType type) const;

	template <typename T>
	void addComponent(ComponentType type, std::unique_ptr<T> component);
	
	void removeComponent(ComponentType type);


	//void updatePosition(sf::Vector2f pos);
	//void updatePosition(float vx, float vy);

	//void move(float dt, float dirX, float dirY);
	//void move(float dirX, float dirY);

	/*virtual void draw(sf::RenderTarget& target) = 0;
	virtual void update(sf::Time dt) = 0;*/

	//virtual void draw(sf::RenderTarget& target);
	//virtual void update(sf::Time dt);
	void update(sf::Time dt);

	//void setTexture(const sf::Texture& texture);

private:
	std::unordered_map<ComponentType, std::unique_ptr<Component>> m_components;

	//sf::Sprite m_sprite; // TODO: Make optional?? or make pointer??

	//sf::RectangleShape m_shape;

	//sf::Vector2f m_position, m_size; // TODO: Make inherit from sf::Transformable instead??
	//float m_movementSpeed{ 10.f };
};


template <typename T>
T GameObject::getComponent(ComponentType type) const
{
	auto found{ m_components.find(type) };

	if (found != m_components.end())
		return dynamic_cast<T>(found->second.get());

	return nullptr;
}


template <typename T>
void GameObject::addComponent(ComponentType type, std::unique_ptr<T> component)
{
	m_components.insert(std::make_pair(type, std::move(component)));
}