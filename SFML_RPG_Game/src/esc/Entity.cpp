#include "Entity.h"



Entity::Entity(EntityId_t id)
	: m_id{ id }
{
}











//void Entity::addComponent(Component_esc::Type type, std::unique_ptr<Component_esc> component)
//{
//	m_components.insert(std::make_pair(type, std::move(component)));
//}


//void Entity::update(sf::Time dt, const sf::Vector2f& pos)
//{
//	//if (m_components.find(Component_esc::Type::Movement) != m_components.end())
//		//m_components[Component_esc::Type::Movement].
//}
//
//void update(sf::Time dt, float vx, float vy)
//{
//
//}
//


//void Entity::draw(sf::RenderTarget& target) const
//{
//
//	if (m_render)
//		m_render->draw(target);
//	//auto found = m_components.find(ComponentType::Render);
//	//if (found != m_components.end())
//		//found->second->update();
//		//dynamic_cast<Render>(found->second);
//		//found->second->draw(target);
//}
//
//
//void Entity::update(sf::Time dt)
//{
//
//	//if ()
//
//	//for (auto itr{ m_components.begin() }; itr != m_components.end(); ++itr)
//		//itr->second->update(dt);
//}
//
//
//void Entity::move(sf::Vector2f pos)
//{
//	//if (m_transform)
//		//m_transform.move()
//}
//
//
//void Entity::move(float dirX, float dirY)
//{
//
//}
//
//
//
//void Entity::addRender(std::unique_ptr<Render> render)
//{
//	m_render = std::move(render);
//}
//
//
//void Entity::addTransform(std::unique_ptr<Transform> transform)
//{
//	m_transform = std::move(transform);
//}
//
////void Entity::addComponent(ComponentType type, std::unique_ptr<Component_esc> component)
////{
////	//m_components.push_back(std::move(component));
////	m_components.insert(std::make_pair(type, std::move(component)));
////}