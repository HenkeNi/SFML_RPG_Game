#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Window
{
public:
	Window(const std::string& filename);


	void		clear(sf::Color color);
	void		draw(sf::Drawable& drawable);
	void		display();

	void		update();
	void		close();

	bool		pollEvent(sf::Event& event);
	void		enableVerticalSync(bool enable);

	inline bool			isOpen() const { return m_window.isOpen(); }
	inline sf::Vector2u getSize() { return m_window.getSize(); }

private:
	void initWindow(const std::string& filename);

private:
	sf::RenderWindow m_window;
};

