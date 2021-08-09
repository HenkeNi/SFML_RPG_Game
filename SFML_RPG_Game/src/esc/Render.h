#pragma once
#include "Component_esc.h"

#include <SFML/Graphics.hpp>

class Render : public Component_esc
{
public:
	Render(const sf::Texture& texture);
	Render(Render&& other) noexcept;

	//virtual void draw(RenderTarget& target, RenderStates states) const override;
	//virtual void draw(sf::RenderTarget& target) const;
	
	void draw(sf::RenderTarget& target) const;
	void setTexture(const sf::Texture& texture);

	inline sf::Sprite& getSprite() { return m_sprite; }

	//virtual Type getType() const override;

private:
	sf::Sprite m_sprite;
};

