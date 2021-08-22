#pragma once

#include "Button.h"
#include "State.h"
#include "UIObject.h"

#include <map>
#include <memory>

class MainMenuState : public State
{
public:
	MainMenuState(SharedContext context, KeyBinding& keyBindings, StateStack& stack);

	virtual void draw()								 override;
	virtual void update(sf::Time dt)				 override;
	virtual void handleEvent(const sf::Event& event) override;

private:
	void initUIComponents();

private:
	std::map<std::string, std::unique_ptr<UIObject>> m_uiComponents; // TODO: Make a UIHandlerClass instead??
	sf::Clock m_buttonPressDelay;
};

