#pragma once
#include "State.h"

class UIObject;

class SettingsState : public State
{
public:
	SettingsState(SharedContext context, KeyBinding& keyBindings, StateStack& stack);

	virtual void draw()								 override;
	virtual bool update(sf::Time dt)				 override;
	virtual bool handleEvent(const sf::Event& event) override;

private:
	void initUIComponents();

private:
	sf::RectangleShape m_background;
	std::map<std::string, std::unique_ptr<UIObject>> m_uiComponents;

};

