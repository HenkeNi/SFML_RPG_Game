#pragma once

#include "Component.h"
#include "Entity.h"
#include "System.h"



#include <memory>
#include <vector>



class EntityManager
{
public:
	EntityManager();


	// Delete move/copy constructor and assignment
	EntityManager(const EntityManager&) = delete;
	EntityManager(EntityManager&&) = delete;

	EntityManager& operator=(const EntityManager&) = delete;
	EntityManager& operator=(EntityManager&&) = delete;

	void update(sf::Time dt);

	// systems
	bool		createSystems();

	// entities
	EntityId_t  createEntity();
	void		destroyEntity(EntityId_t id);

private:
	std::vector<std::unique_ptr<System>> m_systems;
	std::map<EntityId_t, Entity>			m_entities;

	std::vector<std::unique_ptr<Component_esc>> m_components;

};

