#include "Button.h"
#include "../Constants.h"
#include <SFML/Graphics.hpp>



Button::Button(const sf::Font& font, const std::string& text, const sf::Vector2f& position, const sf::Vector2f& size) 
{
	m_text.setFont(font);
	m_text.setString(text);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(22);
	
	m_text.setOrigin(m_text.getLocalBounds().left + m_text.getLocalBounds().width / 2.0f,
					 m_text.getLocalBounds().top + m_text.getLocalBounds().height / 2.0f);
	
	m_text.setPosition(sf::Vector2f(constants::SCR_WIDTH / 2.0f, position.y));
	//m_text.setPosition(position.x + (size.x / 2.f), position.y + (size.y / 2.f));
	//m_text.setOrigin(size.x / 2.f, size.y / 2.f);

	

	m_container.setFillColor(sf::Color::Green);
	m_container.setOrigin(size.x / 2.f, size.y / 2.f);
	m_container.setPosition(sf::Vector2f(constants::SCR_WIDTH / 2.0f, position.y));
	m_container.setSize(size);
	m_container.setOutlineColor(sf::Color::Black);
	m_container.setOutlineThickness(2.f);
}




void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_container, states);
	target.draw(m_text, states);
}



bool Button::isSelectable() const
{
	return false;
}


void Button::handleEvent(const sf::Event& event)
{

}



//void			draw(sf::RenderTarget& target, sf::RenderStates states) const;




//bool Button::isClicked()
//{
//	if (sf::Mouse::isButtonPressed(button)
//	{
//	}
//}




void Button::update(sf::Vector2f mousePos)
{
	m_state = IDLE;
	deselect();
	// Hover...
	if (m_container.getGlobalBounds().contains(mousePos))
	{
		m_state = HOVER;


		// Button clicked...
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_state = ACTIVE;
			select();
		}
	}

	updateBackgroundColor();
}




void Button::updateBackgroundColor()
{
	if (m_state == IDLE)
		m_container.setFillColor({ 139, 0, 0 });
	if (m_state == HOVER)
		m_container.setFillColor({ 94, 10, 11 });
	if (m_state == ACTIVE)
		m_container.setFillColor({ 72, 72, 72 });


}