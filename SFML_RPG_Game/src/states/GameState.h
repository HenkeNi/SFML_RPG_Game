#pragma once
#include "../Player.h"
#include "State.h"

#include <vector>

class GameState : public State
{
public:
	GameState(SharedContext context, KeyBinding& keyBindings, StateStack& stack);

	virtual void draw()								 override;
	virtual bool update(sf::Time dt)				 override;
	virtual bool handleEvent(const sf::Event& event) override;

private:
	void initGameObjects(); // TODO: Better way??
	
private:
	//GameObject m_player;
	Player m_player; // TODO: make unique_ptr instead?

	// Implement a Scene/World class that contains all the GameObjects??
	std::vector<GameObject> m_gameObjects;
};

