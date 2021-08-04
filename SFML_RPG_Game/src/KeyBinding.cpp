#include "KeyBinding.h"




KeyBinding::KeyBinding()
{
	m_keyMap[sf::Keyboard::W] = Player::PlayerAction::MoveUp;
	m_keyMap[sf::Keyboard::A] = Player::PlayerAction::MoveLeft;
	m_keyMap[sf::Keyboard::S] = Player::PlayerAction::MoveDown;
	m_keyMap[sf::Keyboard::D] = Player::PlayerAction::MoveRight;
}


void KeyBinding::assignKey(sf::Keyboard::Key key, Player::PlayerAction action)
{
	m_keyMap[key] = action;
}



Player::PlayerAction KeyBinding::getAction(sf::Keyboard::Key key)
{
	if (m_keyMap.find(key) != m_keyMap.end())
		return m_keyMap[key];

	return Player::PlayerAction::Unkown;
}
