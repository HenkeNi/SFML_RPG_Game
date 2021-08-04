#pragma once

#include <SFML/Graphics.hpp>

namespace constants
{
	// TODO: Make Config/window.init file instead -> read the data from there (screen size, title, etc)..??
	constexpr unsigned int SCR_WIDTH{ 800 };
	constexpr unsigned int SCR_HEIGHT{ 600 };

	const sf::Time TIME_PER_FRAME{ sf::seconds(1.f / 60.f) };
}