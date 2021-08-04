#pragma once
#include "states/State.h"

#include <memory>
#include <stack>

class StateStack
{
public:

	void update(sf::Time dt);
	void draw();
	void handleEvent(const sf::Event& event);
	
	void pushState(std::unique_ptr<State> state);
	void popState();
	void clearStates();

private:
	std::stack<std::unique_ptr<State>> m_states; 
};

