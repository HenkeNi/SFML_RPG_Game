#pragma once
#include "Player.h"

#include <map>

class KeyBinding
{
public:
	KeyBinding();

	void assignKey(sf::Keyboard::Key key, Player::PlayerAction action);
	Player::PlayerAction getAction(sf::Keyboard::Key key); // TEST??

private:
	std::map<sf::Keyboard::Key, Player::PlayerAction> m_keyMap;

};

