#pragma once
#include "../Player.h"
#include "State.h"
#include "../map/TileMap.h"

#include <vector>

class GameState : public State
{
public:
	GameState(SharedContext context, KeyBinding& keyBindings, StateStack& stack);

	virtual void draw()								 override;
	virtual void update(sf::Time dt)				 override;
	virtual void handleEvent(const sf::Event& event) override;


private:
	void initTileMap();
	void initGameObjects(); // TODO: Better way?? World class?

private:
	TileMap				    m_tileMap; // Combine with GameObjects??

	// Implement a Scene/World class that contains all the GameObjects??
	std::vector<GameObject> m_gameObjects;
	
	
	// bool m_gameIsPaused; - needed for later??
};

