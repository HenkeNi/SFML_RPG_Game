#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class Window
{
public:
	Window(const std::string& filename);

	void		close();
	void		clear();
	void		display();

	void		draw();

	bool		pollEvent(sf::Event& event);
	inline bool isOpen() const { return m_window.isOpen(); }

private:
	void initWindow(const std::string& filename);

private:
	sf::RenderWindow m_window;
};

