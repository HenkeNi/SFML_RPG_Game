#pragma once

#include "BaseSystem.h"

#include <SFML/Graphics.hpp>
#include <vector>

// Component_esc System: will have a reference to all the components it cares about 
class System : public BaseSystem
{
public:
	virtual ~System() = default;

	virtual bool init() = 0;
	virtual void update(sf::Time dt) = 0; // pass in transform to rendable?? 

private:
	std::vector<std::tuple<Component_esc*, unsigned>> m_components;
};

