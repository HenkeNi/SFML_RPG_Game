#include "UIObject.h"



//void UIObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//	target.draw(m_container, states);
//}




void UIObject::select()
{
	m_isSelected = true;
}


void UIObject::deselect()
{
	m_isSelected = false;
}



void UIObject::activate()
{
	m_isActive = true;
}


void UIObject::deactivate()
{
	m_isActive = false;
}