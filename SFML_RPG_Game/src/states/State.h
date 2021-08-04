#pragma once
#include "../KeyBinding.h"
#include "../ResourceHolder.h"

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class StateStack;

class State
{
public:
	State(sf::RenderWindow& window, KeyBinding& keyBindings, ResourceHolder<sf::Font, std::string>& fonts, ResourceHolder<sf::Texture, std::string>& textures, StateStack& stack);
	virtual ~State() = default;

	//virtual void draw(sf::RenderTarget& target)	= 0;
	virtual void draw() = 0;
	virtual bool update(sf::Time dt) = 0;
	virtual bool handleEvent(const sf::Event& event) = 0;

	//virtual void onActivate();
	//virtual void onDestroy();

	// Find other solution??
	virtual void updateMousePositions(); // TODO: REMOVE VIRTUAL??

protected:
	void requestStackPop();
	void requestStackPush(std::unique_ptr<State> state);
	/*void requestStackPush();
	void requestStackPop();
	void requestStateClear();*/
	 

protected:
	std::vector<sf::Texture> m_textures;
	sf::RenderWindow&		 m_windowContext; // (aggregation) - make as ptr or shared_ptr instead??
	KeyBinding&				 m_keyBindingContext;
	StateStack&				 m_stackContext;


	// TODO: Create context class/struct??
	ResourceHolder<sf::Font, std::string>&	  m_fontsContext; // make optional??
	ResourceHolder<sf::Texture, std::string>& m_texturesContext;

	// bool m_shouldQuit; ?? - if Game should terminate

	sf::Vector2i m_mousePosScreen; // Make to uniform instead?? Create Mouse Class
	sf::Vector2i m_mousePosWindow;
	sf::Vector2f m_mousePosView;
};

