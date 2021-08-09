#include "Component_esc.h"


Component_esc::Component_esc()
	: m_id{ INVALID_ENTITY_ID }, m_poolIndex{ INVALID_POOL_INDEX }
{
}


void Component_esc::setEntityId(EntityId_t id)
{ 
	m_id = id;
}


void Component_esc::setPoolIndex(std::size_t index) 
{ 
	m_poolIndex = index; 
}