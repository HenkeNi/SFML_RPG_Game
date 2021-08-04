#pragma once

#include "../Player.h"
#include "State.h"

class GameState : public State
{
public:
	GameState(sf::RenderWindow& window, KeyBinding& keyBindings, ResourceHolder<sf::Font, std::string>& fonts, ResourceHolder<sf::Texture, std::string>& textures, StateStack& stack);

	virtual void draw()								 override;
	virtual bool update(sf::Time dt)				 override;
	virtual bool handleEvent(const sf::Event& event) override;

private:
	//Entity m_player;
	// TODO: resourceHolder<sf::Texture, std::string>?? 
	Player m_player;
};

