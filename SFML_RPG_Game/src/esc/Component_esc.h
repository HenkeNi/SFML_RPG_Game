#pragma once
#include "EntitySystemTypes.h"

#include <SFML/System.hpp>

class Component_esc
{
public:
	Component_esc();
	virtual ~Component_esc() = default;

	virtual bool	  init(void* pDescription) = 0; // TODO

	void			  setEntityId(EntityId_t id);
	inline EntityId_t getEntityId() const { return m_id; }

	void			  setPoolIndex(std::size_t index); 
	std::size_t		  getPoolIndex() const { return m_poolIndex; }

	virtual ComponentType getComponentType() const = 0;

	//virtual void update(sf::Time dt) = 0;

private:
	EntityId_t m_id;		 // a Component_esc is connected to an Entity through an Id
	std::size_t m_poolIndex; // What index in the array of Component_esc's in the EntityManager

	static constexpr std::size_t INVALID_POOL_INDEX = std::numeric_limits<std::size_t>::max();

};

