#include "MainMenuState.h"
#include "../ui_objects/Button.h"
#include "../ui_objects/Label.h"

#include <iostream>


MainMenuState::MainMenuState(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: State{ context, keyBindings, stack }
{
	initUIComponents();
}


void MainMenuState::draw()
{
	//m_windowContext.draw(m_background); // TODO: FIX ?? - maybe pass in RenderTarget instead?
	m_context.m_windowPtr->draw(m_background);

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		m_context.m_windowPtr->draw(*itr->second);

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







	// TODO: Check if is selectable... (put code in own function??)

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
	{
		if (itr->second->isSelectable())
		{
			// TODO: this component can be pressed??!?
		}
	}



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
	m_background.setTexture(m_context.m_texturesPtr->getResource("main_menu_background"));
	m_background.setScale({ 1.5f, 1.5f });
	
	//m_background.setSize(static_cast<sf::Vector2f>(m_windowContext.getSize()));
	

	sf::Vector2f playPosition{ static_cast<float>(m_context.m_windowPtr->getPosition().x - 75.f), static_cast<float>(m_context.m_windowPtr->getPosition().y + 150) };
	Button playBtn{ m_context.m_fontsPtr->getResource("main-font"), "START GAME", playPosition, { 400.f, 70.f} };
	//button.setPosition({ 300.0f, 200.0f });
	playBtn.setScale(2.0f, 2.0f);

	//m_uiComponents["PlayBtn"] = button;
	//m_uiComponents.insert(std::pair<std::string, std::unique_ptr<Button>>("PLAY", std::make_unique<Button>(playBtn)));
	m_uiComponents.insert(std::make_pair("START_GAME", std::make_unique<Button>(playBtn)));
	//m_uiComponents.push_back(std::make_unique<Button>(button)); // TODO: make stack instead??



	sf::Vector2f quitPosition{ 400, 400 };
	Button quitBtn{ m_context.m_fontsPtr->getResource("main-font"), "QUIT GAME", quitPosition, { 400.f, 70.f} };
	m_uiComponents.insert(std::make_pair("QUIT", std::make_unique<Button>(quitBtn)));
	//m_uiComponents.insert(std::pair<std::string, std::unique_ptr<Button>>("QuitBtn", std::make_unique<Button>(quitBtn)));


	Label title{ m_context.m_fontsPtr->getResource("main-font"), "SFML RPG Game", sf::Vector2f{0.f, 80.f}, { 400.f, 70.f } };
	m_uiComponents.insert(std::make_pair("TITLE", std::make_unique<Label>(title)));
}