#include "Window.h"

#include <fstream>
#include <iostream>
#include <string>

Window::Window(const std::string& filename)
{
	initWindow(filename);
}


void Window::clear(sf::Color color)
{
	m_window.clear(color);
}


void Window::draw(sf::Drawable& drawable)
{
	m_window.draw(drawable);
}


void Window::display()
{
	m_window.display();
}



void Window::update()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			close();
	}
}


void Window::close()
{
	m_window.close();
}


bool Window::pollEvent(sf::Event& event)
{
	return m_window.pollEvent(event);
}


void Window::enableVerticalSync(bool enable)
{
	m_window.setVerticalSyncEnabled(enable);
}

void Window::initWindow(const std::string& filename)
{
	std::ifstream ifs(filename);

	unsigned width{ 0 }, height{ 0 };
	std::string title;
	
	if (!ifs.is_open())
		std::cerr << "Failed to read from window config file " << filename << '\n';
	else
	{
		std::getline(ifs, title);
		ifs >> width >> height;

	}

	ifs.close();
	m_window.create(sf::VideoMode{ width, height }, title);
}
