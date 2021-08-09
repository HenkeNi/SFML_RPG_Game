#include "Window.h"

#include <fstream>
#include <iostream>
#include <string>

Window::Window(const std::string& filename)
{
	initWindow(filename);
}


void Window::close() 
{
	m_window.close();
}


void Window::clear()
{
	m_window.clear();
}


void Window::display()
{
	m_window.display();
}


void Window::draw()
{
	/*m_window.draw()*/
}

bool Window::pollEvent(sf::Event& event)
{
	return m_window.pollEvent(event);
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
