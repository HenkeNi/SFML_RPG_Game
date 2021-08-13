#include "Player.h"
#include "game_object/components/Rendering.h"
#include "game_object/components/Movement.h"

#include <iostream>
#include <memory>


Player::Player(const sf::Texture& texture, sf::RenderWindow& target, const sf::Vector2f& startPos)
	//: m_sprite{ texture, sf::Vector2f{20.f, 20.f} }
{
	m_object.addComponent(ComponentType::Rendering, std::make_unique<Rendering>(texture, target, startPos));
	m_object.addComponent(ComponentType::Movement, std::make_unique<Movement>(m_object.getComponent<Rendering*>(ComponentType::Rendering)));

	//m_sprite.setTexture(texture);


	// *** m_entity.addRender(std::make_unique<Render>(texture));
	//m_entity.addComponent(Entity::ComponentType::Render, std::make_unique<Render>(texture));
}


//Player& Player::operator=(const Player& other)
//{
//	m_object = other.m_object;
//	
//	return *this;
//}


void Player::draw(sf::RenderTarget& target)
{

	// TODO: update GameObject instead..

	auto renderComp{ m_object.getComponent<Rendering*>(ComponentType::Rendering) };

	if (renderComp)
		renderComp->draw(target);

	// *** m_entity.draw(target);
	//m_sprite.draw(target);
}

void Player::update(sf::Time dt)
{
	m_object.update(dt);
	// *** m_entity.update(dt);
	//m_sprite.update(dt);
}

void Player::handleAction(PlayerAction action)
{
	//std::cout << "action is walk up? " << (action == Player::PlayerAction::MoveUp) << '\n';
	//std::cout << "action is unkown? " << (action == Player::PlayerAction::Unkown) << '\n';

	//std::cout << int(action) << '\n';
}