#include "Player.h"

#include <iostream>


void Player::draw(sf::RenderTarget& target)
{
	m_sprite.draw(target);
}

void Player::update(sf::Time dt)
{
	m_sprite.update(dt);
}

void Player::handleAction(PlayerAction action)
{
	std::cout << "action is walk up? " << (action == Player::PlayerAction::MoveUp) << '\n';
	std::cout << "action is unkown? " << (action == Player::PlayerAction::Unkown) << '\n';

	std::cout << int(action) << '\n';
}