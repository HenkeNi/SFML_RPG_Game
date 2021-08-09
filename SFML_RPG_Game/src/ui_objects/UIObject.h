#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Drawable.hpp>
//#include <SFML/Graphics/Transformable.hpp>
//#include <SFML/System/NonCopyable.hpp>


class UIObject : public sf::Drawable, public sf::Transformable
{
public:
	virtual ~UIObject() = default;

	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual bool isSelectable() const = 0; // TODO: Rename clickable or something??
	inline  bool isSelected()   const { return m_isSelected; }
	
	// TODO: combine to toggle() or toggleSelect() => m_isSelected = !m_isSelected;
	void select();
	void deselect();
	//virtual void select();
	//virtual void deselect();

	inline bool isActive() const { return m_isActive; }
	//inline virtual bool isActive() const { return m_isActive; }
	//virtual void activate();
	//virtual void deactivate();
	void activate();
	void deactivate();


	virtual void handleEvent(const sf::Event& event) = 0;


	// TEST
	virtual void update(sf::Vector2f mousePos) = 0;



private:
	bool m_isSelected{ false }, m_isActive{ false };

	//sf::RectangleShape  m_container; // Change to sf::Sprite

};

