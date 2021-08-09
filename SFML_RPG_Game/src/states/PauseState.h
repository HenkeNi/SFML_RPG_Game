#pragma once
#include "State.h"

class PauseState : public State
{
public:
	PauseState(SharedContext context, KeyBinding& keyBindings, StateStack& stack);

	virtual void draw()								 override;
	virtual bool update(sf::Time dt)				 override;
	virtual bool handleEvent(const sf::Event& event) override;

private:
	sf::RectangleShape m_background;
};

