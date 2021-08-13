#include "Label.h"

#include "../Constants.h"

Label::Label(const sf::Font& font, const std::string& text, const sf::Vector2f& position, const sf::Vector2f& size)
{
	m_text.setFont(font);
	m_text.setString(text);
	m_text.setCharacterSize(50); // Make input parameter
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setOutlineThickness(2.f);


	//m_text.setOrigin(m_text.getLocalBounds().left + m_text.getLocalBounds().width / 2.0f,
	//	m_text.getLocalBounds().top + m_text.getLocalBounds().height / 2.0f);
	//m_text.setOrigin(m_text.getLocalBounds().left / 2.f, m_text.getLocalBounds().top / 2.f);

	m_text.setPosition(position);
	m_text.setOrigin(size.x / 2.f, size.y / 2.f);
	
	//m_text.setPosition(sf::Vector2f(constants::SCR_WIDTH / 2.0f, position.y));
}


void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_text, states);
}


bool Label::isSelectable() const
{
	return false;
}

void Label::handleEvent(const sf::Event& event)
{

}

void Label::update(sf::Vector2f mousePos)
{

}
