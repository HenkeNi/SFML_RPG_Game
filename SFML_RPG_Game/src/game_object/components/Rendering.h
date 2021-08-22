#pragma once
#include "Component.h"

#include <vector>


/*
*	TODO: instead of Movement having a ref to a Render component, let Render have a ref to movement comp (before draw -> check or move??)
*/
class Rendering : public Component
{
public:
	Rendering(const sf::Texture& texture, sf::RenderWindow& target, const sf::Vector2f& startPos);

	void draw(sf::RenderTarget& target) const;
	void draw() const;
	void draw(sf::Drawable& drawable) const;

	//void addDrawable(const sf::Drawable& drawable);
	//void addShape(sf::RectangleShape* shape);

	virtual void update(sf::Time dt) override;
	virtual void handleEvent(const sf::Event& event) override;

	inline sf::Sprite&   getSprite()   { return m_sprite; }
	inline sf::Vector2u  getTextureSize()     { return m_sprite.getTexture()->getSize(); }
	inline sf::IntRect  getRectSize() const { return m_partDrawn; }
	//inline sf::Vector2f  getPosition() { return m_sprite.getPosition(); }
	//inline sf::FloatRect getSize()   { return m_sprite.getTexture()->getSize(); }


	void setTextureRect(const sf::IntRect& rect);

private:
	sf::Sprite m_sprite; // MAYBE a drawstack instead??? or a vector of sf::Drawable??
	//std::vector<sf::Drawable*> m_drawables;
	//sf::RectangleShape* m_shape;

	sf::IntRect m_partDrawn;

	sf::RenderWindow& m_target;
	//unsigned int m_frameCount; -- store number of frames in sprite here?? - maybe bad idea!
};

