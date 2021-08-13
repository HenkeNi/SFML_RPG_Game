#pragma once

#include "Component.h"
/*
*	TODO: instead of Movement having a ref to a Render component, let Render have a ref to movement comp (before draw -> check or move??)
*/
class Rendering : public Component
{
public:
	Rendering(const sf::Texture& texture, sf::RenderWindow& target, const sf::Vector2f& startPos);

	void draw(sf::RenderTarget& target) const;
	void draw() const;
	virtual void update(sf::Time dt) override;

	inline sf::Sprite&   getSprite() { return m_sprite; }
	inline sf::FloatRect getSize()   { return m_sprite.getLocalBounds(); }

	void setTextureRect(const sf::IntRect& rect);

private:
	sf::Sprite m_sprite;
	sf::RenderWindow& m_target;
	//unsigned int m_frameCount; -- store number of frames in sprite here?? - maybe bad idea!
};

