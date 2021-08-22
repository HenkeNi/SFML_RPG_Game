#pragma once
#include "State.h"

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

	inline int getSize() const { return m_states.size(); }

private:
	std::stack<std::unique_ptr<State>> m_states; 
};

