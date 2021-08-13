#pragma once
#include "Component.h"

class Movement;

class Input : public Component
{
public:
	Input(Movement* movement);

	virtual void update(sf::Time dt) override;

private:
	Movement* m_movementComponent;
	// TODO: store keybindings...

};

