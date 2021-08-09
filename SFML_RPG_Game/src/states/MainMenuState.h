#pragma once

#include "../ui_objects/UIObject.h"
#include "../ui_objects/Button.h"
#include "State.h"

#include <map>
#include <memory>

class MainMenuState : public State
{
public:
	MainMenuState(SharedContext context, KeyBinding& keyBindings, StateStack& stack);

	virtual void draw()								 override;
	virtual bool update(sf::Time dt)				 override;
	virtual bool handleEvent(const sf::Event& event) override;


private:
	void initFonts(); // TEST...

	void initUIComponents();


private:
	sf::Sprite m_background;


	std::map<std::string, std::unique_ptr<UIObject>> m_uiComponents;
	//std::vector<std::unique_ptr<UIObject>> m_uiComponents; // Make own class, or map instead?? 

};

