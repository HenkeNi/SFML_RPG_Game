#pragma once
#include "UIObject.h"

class Background : public UIObject
{
public:
	Background(const sf::Texture& texture, const sf::Vector2f& size, const sf::Vector2f& position = { 0.0f, 0.0f });

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual bool isSelectable() const override;

	virtual void handleEvent(const sf::Event& event) override;
	virtual void update(sf::Vector2f mousePos) override;

private:
	sf::Sprite m_backgroundSprite;
};

