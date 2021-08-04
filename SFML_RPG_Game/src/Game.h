#pragma once
#include "KeyBinding.h"
#include "ResourceHolder.h"
#include "StateStack.h"

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
	void initStates();

	// TODO: Combine -> loadResources();
	void loadFonts();
	void loadTextures();

private:
	sf::RenderWindow m_window;
	StateStack		 m_stateStack;
	KeyBinding		 m_keyBindings;

	// TODO: Textures and fonts??
	ResourceHolder<sf::Font, std::string>    m_fonts;
	ResourceHolder<sf::Texture, std::string> m_textures; // Rename textureHolder?

};

