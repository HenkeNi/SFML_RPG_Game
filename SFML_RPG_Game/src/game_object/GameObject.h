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
	GameObject() = default;
	GameObject(GameObject&& other) noexcept;

	virtual ~GameObject() = default;

	template <typename T>
	T getComponent(ComponentType type) const;

	template <typename T>
	void addComponent(ComponentType type, std::unique_ptr<T> component);

	void removeComponent(ComponentType type);

	void update(sf::Time dt);

private:
	std::unordered_map<ComponentType, std::unique_ptr<Component>> m_components;
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