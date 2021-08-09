#pragma once
#include "KeyBinding.h"
#include "ResourceHolder.h"
#include "StateStack.h"
#include "Window.h"

#include <SFML/Graphics.hpp>

#include <map>
#include <stack>
#include <string>

class Game final 
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();
	
	//void initKeyBindings(); // TODO: FIX other way??
	void initWindow(const std::string& filename);
	void initStates();

	// TODO: Combine -> loadResources();
	void loadFonts();
	void loadTextures();

private:
	//Window m_window;
	sf::RenderWindow m_window;
	StateStack		 m_stateStack;
	KeyBinding		 m_keyBindings;

	// TODO: Textures and fonts??
	TextureHolder_t m_textures;
	FontHolder_t	m_fonts;

};

