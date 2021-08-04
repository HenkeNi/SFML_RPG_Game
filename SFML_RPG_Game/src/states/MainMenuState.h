#pragma once

#include "../components/Component.h"
#include "../components/Button.h"
#include "State.h"

#include <map>
#include <memory>

class MainMenuState : public State
{
public:
	MainMenuState(sf::RenderWindow& window, KeyBinding& keyBindings, ResourceHolder<sf::Font, std::string>& fonts, ResourceHolder<sf::Texture, std::string>& textures, StateStack& stack);

	virtual void draw()								 override;
	virtual bool update(sf::Time dt)				 override;
	virtual bool handleEvent(const sf::Event& event) override;


private:
	void initFonts(); // TEST...

	void initUIComponents();


private:
	sf::RectangleShape m_background; // TODO: remove... 
	sf::Sprite m_backgroundSprite;


	std::map<std::string, std::unique_ptr<Component>> m_uiComponents;
	//std::vector<std::unique_ptr<Component>> m_uiComponents; // Make own class, or map instead?? 

};

