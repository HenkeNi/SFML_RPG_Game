#include "Transform.h"



Transform::Transform()
	: m_rotation{ 0.f }, m_scale{ 1.f, 1.f }
{
}


ComponentType Transform::getComponentType() const
{
	return ComponentType::TRANSFORM;
}


bool Transform::init(void* pDescription) 
{

}