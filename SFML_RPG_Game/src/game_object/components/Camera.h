#pragma once

#include "Component.h"

class Movement;

class Camera : public Component
{
public:
	Camera(sf::RenderWindow& window, Movement* movement = nullptr);

	virtual void update(sf::Time dt) override;
	virtual void handleEvent(const sf::Event& event) override;

	void updateViewPos();
	void resizeView();

private:
	sf::View		  m_view;
	sf::RenderWindow& m_window;

	Movement*		  m_movement; // use reference instead? - needs to have it...?
};

