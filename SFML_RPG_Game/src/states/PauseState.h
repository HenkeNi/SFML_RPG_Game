#pragma once
#include "State.h"

class UIObject;

class PauseState : public State
{
public:
	PauseState(SharedContext context, KeyBinding& keyBindings, StateStack& stack);

	virtual void draw()								 override;
	virtual void update(sf::Time dt)				 override;
	virtual void handleEvent(const sf::Event& event) override;

private:
	void initUIComponents();

private:
	sf::RectangleShape m_background;
	std::map<std::string, std::unique_ptr<UIObject>> m_uiComponents;

	bool m_popState{ false };
};

