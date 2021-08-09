#pragma once
#include "UIObject.h"

class Label : public UIObject
{
public:
	Label(const sf::Font& font, const std::string& text, const sf::Vector2f& position, const sf::Vector2f& size);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual bool isSelectable() const override;

	virtual void handleEvent(const sf::Event& event) override;
	virtual void update(sf::Vector2f mousePos) override;

private:
	sf::Text m_text;
};

