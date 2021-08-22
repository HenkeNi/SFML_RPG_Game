#include "Game.h"
#include "states/GameState.h"
#include "states/MainMenuState.h"
#include "Constants.h"

#include <fstream>
#include <iostream>

Game::Game()
	//: m_window{"config/window.init"}
{
	initWindow("config/window.init");
	m_window.setVerticalSyncEnabled(true);

	// TODO: set anti aliasing level??
	//sf::ContextSettings windowSettings;
	//windowSettings.antialiasingLevel = 0;
	//m_window = sf::RenderWindow{ sf::VideoMode{ constants::SCR_WIDTH, constants::SCR_HEIGHT }, "SFML RPG", sf::Style::Default, windowSettings };

	loadFonts();
	loadTextures();
	initStates();
	initStatistics();
}

// run the game
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate{ sf::Time::Zero };

	// Game loop
	while (m_window.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > constants::TIME_PER_FRAME)
		{
			timeSinceLastUpdate -= constants::TIME_PER_FRAME;
			processEvents();
			update(constants::TIME_PER_FRAME);
		}
		render();
		updateStatistics(timeSinceLastUpdate);
	}
}

// process events from window
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		m_stateStack.handleEvent(event);

		if (event.type == sf::Event::Closed)
			m_window.close();
	}

}

// update game logic
void Game::update(sf::Time elapsedTime)
{
	m_stateStack.update(elapsedTime);
}

// render game to the screen
void Game::render()
{
	m_window.clear();

	m_stateStack.draw();
	m_window.draw(m_statisticsText);

	m_window.display();
}


//void Game::initKeyBindings()
//{
//	m_keyBindings[sf::Keyboard::W] = Player::PlayerAction::WalkUp;
//	m_keyBindings[sf::Keyboard::A] = Player::PlayerAction::WalkLeft;
//	m_keyBindings[sf::Keyboard::S] = Player::PlayerAction::WalkDown;
//	m_keyBindings[sf::Keyboard::D] = Player::PlayerAction::WalkRight;
//}


void Game::initWindow(const std::string& filename)
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

// push states to state stack
void Game::initStates()
{
	m_stateStack.pushState(std::make_unique<GameState>(SharedContext{ &m_window, &m_textures, &m_fonts }, m_keyBindings, m_stateStack));
	m_stateStack.pushState(std::make_unique<MainMenuState>(SharedContext{ &m_window, &m_textures, &m_fonts }, m_keyBindings, m_stateStack));
}


void Game::initStatistics()
{
	m_statisticsText.setFont(m_fonts.getResource("main-font"));
	m_statisticsText.setPosition(5.f, 5.f);
	m_statisticsText.setCharacterSize(15);
	m_statisticsText.setFillColor(sf::Color::Yellow);
}


void Game::loadFonts()
{
	m_fonts.load("main-font", "assets/fonts/Sansation.ttf");
}


void Game::loadTextures()
{
	m_textures.load("main_menu_background", "assets/images/background.jpg"); // TODO: should be texture?? or image??
	m_textures.load("player_sheet", "assets/textures/pirate_sheet.png");
	m_textures.load("tree", "assets/textures/tree.png");
	m_textures.load("tree2", "assets/textures/tree2.png");
	m_textures.load("bush", "assets/textures/bush.png");
	m_textures.load("berry_bush", "assets/textures/berry_bush.png");
	m_textures.load("rock", "assets/textures/rock.png");
	m_textures.load("chest", "assets/textures/chest.png");
	m_textures.load("barrel", "assets/textures/barrel.png");
	m_textures.load("ship_1", "assets/textures/simple_ship.png");
	m_textures.load("palm_1", "assets/textures/palm_tree.png");




}



void Game::updateStatistics(sf::Time elapsedTime)
{
	static sf::Time updateTime;
	static int frames;

	updateTime += elapsedTime;
	++frames;

	if (updateTime > sf::seconds(1.0f))
	{
		m_statisticsText.setString("Fps/sec: " + std::to_string(frames) + "\n" +
			"Time/update: " + std::to_string(updateTime.asMicroseconds() / frames) + "us");

		updateTime -= sf::seconds(1.0f);
		frames = 0;
	}
}