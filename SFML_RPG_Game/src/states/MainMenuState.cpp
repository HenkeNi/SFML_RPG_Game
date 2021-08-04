#include "MainMenuState.h"
#include "../components/Button.h"

#include <iostream>



MainMenuState::MainMenuState(sf::RenderWindow& window, KeyBinding& keyBindings, ResourceHolder<sf::Font, std::string>& fonts, ResourceHolder<sf::Texture, std::string>& textures, StateStack& stack)
	: State{ window, keyBindings, fonts, textures, stack }
{
	m_background.setSize(static_cast<sf::Vector2f>(window.getSize()));
	m_background.setFillColor(sf::Color::Blue);


	initUIComponents();

}


void MainMenuState::draw()
{
	//m_windowContext.draw(m_background); // TODO: FIX ?? - maybe pass in RenderTarget instead?
	m_windowContext.draw(m_backgroundSprite);

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		m_windowContext.draw(*itr->second);

	//for (const auto& c : m_uiComponents)
	//	m_windowContext.draw(*c);

}


bool MainMenuState::update(sf::Time dt)
{
	updateMousePositions();

	std::cout << "Mouse pos: " << m_mousePosView.x << ", " << m_mousePosView.y << '\n';


	//for (const auto& comp : m_uiComponents)
	//	comp->update(m_mousePosView);

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		itr->second->update(m_mousePosView);




	// FIX: put in function or handle differently (FIX THIS!!!!)
	if (m_uiComponents["START_GAME"]->isSelected()) // TOOD: start game....
	{
		requestStackPop();
		return false;
	}

	if (m_uiComponents["QUIT"]->isSelected())
		; // Request clear stack??


	return false;
}


bool MainMenuState::handleEvent(const sf::Event& event)
{
	return false;
}



//void MainMenuState::initFonts()
//{
//	//if ()
//}





void MainMenuState::initUIComponents()
{
	m_backgroundSprite.setTexture(m_texturesContext.getResource("main_menu_background"));
	m_backgroundSprite.setScale({ 1.5f, 1.5f });
	
	//m_backgroundSprite.setSize(static_cast<sf::Vector2f>(m_windowContext.getSize()));
	

	sf::Vector2f playPosition{ static_cast<float>(m_windowContext.getPosition().x - 75.f), static_cast<float>(m_windowContext.getPosition().y + 150) };
	Button playBtn{ m_fontsContext.getResource("main-font"), "START GAME", playPosition, { 400.f, 70.f} };
	//button.setPosition({ 300.0f, 200.0f });
	playBtn.setScale(2.0f, 2.0f);

	//m_uiComponents["PlayBtn"] = button;
	//m_uiComponents.insert(std::pair<std::string, std::unique_ptr<Button>>("PLAY", std::make_unique<Button>(playBtn)));
	m_uiComponents.insert(std::make_pair("START_GAME", std::make_unique<Button>(playBtn)));
	//m_uiComponents.push_back(std::make_unique<Button>(button)); // TODO: make stack instead??



	sf::Vector2f quitPosition{ 400, 400 };
	Button quitBtn{ m_fontsContext.getResource("main-font"), "QUIT GAME", quitPosition, { 400.f, 70.f} };
	m_uiComponents.insert(std::make_pair("QUIT", std::make_unique<Button>(quitBtn)));
	//m_uiComponents.insert(std::pair<std::string, std::unique_ptr<Button>>("QuitBtn", std::make_unique<Button>(quitBtn)));

}