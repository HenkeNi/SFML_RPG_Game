#include "Component.h"



//void Component::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//	target.draw(m_container, states);
//}




void Component::select()
{
	m_isSelected = true;
}


void Component::deselect()
{
	m_isSelected = false;
}



void Component::activate()
{
	m_isActive = true;
}


void Component::deactivate()
{
	m_isActive = false;
}