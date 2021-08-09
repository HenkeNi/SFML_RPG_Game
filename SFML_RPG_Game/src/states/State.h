#pragma once
#include "../KeyBinding.h"
#include "../SharedContext.h"
//#include "../ResourceHolder.h"

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class StateStack;

class State
{
public:
	State(SharedContext context, KeyBinding& keyBindings, StateStack& stack);
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
	void requestStateClear();
	 

protected:
	SharedContext m_context;
	StateStack&	  m_stackContext;
	KeyBinding&				 m_keyBindingContext; // TODO: put in SharedContext?


	// bool m_shouldQuit; ?? - if Game should terminate

	sf::Vector2i m_mousePosScreen; // Make to uniform instead?? Create Mouse Class
	sf::Vector2i m_mousePosWindow;
	sf::Vector2f m_mousePosView;
};

