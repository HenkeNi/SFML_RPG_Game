#pragma once

#include "ResourceHolder.h"

#include <SFML/Graphics/RenderWindow.hpp>

struct SharedContext
{
	sf::RenderWindow* m_windowPtr  { nullptr }; // TODO: make own class (Window - Class)??
	TextureHolder_t*  m_texturesPtr{ nullptr };
	FontHolder_t*	  m_fontsPtr   { nullptr };
	
};