#pragma once
#include "Component_esc.h"

#include "EntitySystemTypes.h"
#include "Render.h"


#include <SFML/Graphics.hpp>

#include <map>
#include <memory>
#include <unordered_set>


class Entity
{
public:
	explicit Entity(EntityId_t id);

	inline EntityId_t getId() const { return m_id; }

	template <typename ComponentType>
	ComponentType* getComponent() const
	{
		auto found{ m_components.find(ComponentType::ID) };

		if (found != m_components.end())
			return found->second;

		return nullptr;
	}

private:
	EntityId_t m_id;
	std::map<EntityId_t, std::unique_ptr<Component_esc>> m_components;
};


/*
* PROBLME!! - can't call functions lie: move or draw with a Component_esc object (needs to do a cast - expensive?)
*/


//class Entity
//{
//public:
//	Entity(int id);
//
//	//void addComponent(Component_esc::Type type, std::unique_ptr<Component_esc> component);
//
//
//	// TODO: either return component or have function for draw.. etc.???
//
//	void update(sf::Time dt, const sf::Vector2f& pos);
//	void update(sf::Time dt, float vx, float vy);
//
//private:
//	EntityId_t m_id;
//	std::map<EntityId_t, Component_esc> m_components;
//
//
//	std::unique_ptr<Movement> m_movementComponent;
//	std::unique_ptr<Render> m_renderComponent;
//	
//	//std::unordered_set<std::unique_ptr<Component_esc>> m_components;
//	//std::map<Component_esc::Type, std::unique_ptr<Component_esc>> m_components;
//
//	// Ptr to a World (Game world or scene), when adding a component it gets added to world??
//
//};

//// TODO: rename to GameObject??
//class Entity
//{
////public:
////	enum class ComponentType
////	{
////		Render, Velocity
////	};
//
//public:	
//
//	void draw(sf::RenderTarget& target) const; 
//	void update(sf::Time dt);
//
//	void move(sf::Vector2f pos);
//	void move(float dirX, float dirY);
//
//	void addRender(std::unique_ptr<Render> render);
//	void addTransform(std::unique_ptr<Transform> transform);
//
//
//	// ??
//	void createRender(const sf::Texture& texture);
//
//	//void addComponent(ComponentType type, std::unique_ptr<Component_esc> component);
//
//private:
//	std::unique_ptr<Render>	   m_render   { nullptr };
//	std::unique_ptr<Transform> m_transform{ nullptr };
//
//	//std::map<ComponentType, std::unique_ptr<Component_esc>>  m_components; // use map instead?? in draw -> check if map.find(Drawable)
//	
//};
//
