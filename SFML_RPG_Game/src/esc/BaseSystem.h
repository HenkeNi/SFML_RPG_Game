#pragma once

#include <SFML/Graphics.hpp>

class Entity;
class EntityManager;

class BaseSystem
{
public:
	explicit BaseSystem(EntityManager* pEntityManager) : m_pEntityManager{ pEntityManager } {}
	virtual ~BaseSystem() = default;

	virtual void onEntityCreated(const Entity& entity) = 0;
	virtual void onEntityDestroyed(const Entity& entity) = 0;

	//virtual bool init() = 0;
	//virtual void update(sf::Time dt) = 0;


protected:
	EntityManager* m_pEntityManager;

};