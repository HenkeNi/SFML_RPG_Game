#pragma once

#include "Component.h"

#include <SFML/Graphics.hpp>
#include <string>

/*
*	TODO: include callback function 
*/

enum ButtonState
{
	IDLE, HOVER, ACTIVE // TODO: rename clicked to ACtive ???
};

class Button : public Component
{
public:
	Button(const sf::Font& font, const std::string& text, const sf::Vector2f& position, const sf::Vector2f& size);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual bool			isSelectable() const override;
	//virtual void			select();
	//virtual void			deselect();

	//virtual void			activate();
	//virtual void			deactivate();

	virtual void			handleEvent(const sf::Event& event) override;
	//bool isClicked();



	//void setBackgroundsColor(sf::Color color);

	virtual void update(sf::Vector2f mousePos) override;


	//inline bool isPressed() { return m_state == ACTIVE; }


private:
	//virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//void			draw(sf::RenderTarget& target, sf::RenderStates states) const; -- not needed since drawable?!




	void updateBackgroundColor();

private:
	sf::RectangleShape  m_container; // Change to sf::Sprite
	//const sf::Font&		m_font; // change to sf::Text (needed??)
	sf::Text			m_text;


	ButtonState			m_state{ IDLE };

};

