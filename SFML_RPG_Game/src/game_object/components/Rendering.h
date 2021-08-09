#pragma once

#include "Component.h"

/*
*	TODO: instead of Movement having a ref to a Render component, let Render have a ref to movement comp (before draw -> check or move??)
*/
class Rendering : public Component
{
public:
	Rendering(const sf::Texture& texture);

	void draw(sf::RenderTarget& target) const;
	virtual void update(sf::Time dt) override;

	inline sf::Sprite& getSprite() { return m_sprite; }

private:
	sf::Sprite m_sprite;
};

