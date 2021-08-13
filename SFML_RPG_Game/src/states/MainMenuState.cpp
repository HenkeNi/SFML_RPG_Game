#include "MainMenuState.h"
#include "SettingsState.h"
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
	m_context.m_windowPtr->draw(m_background);

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		m_context.m_windowPtr->draw(*itr->second);
}


bool MainMenuState::update(sf::Time dt)
{
	updateMousePositions();

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



	// FIX: put in function or handle differently (FIX THIS!!!!) PUT IN HANDLEEVENT???
	if (m_uiComponents["START_GAME"]->isSelected()) // TOOD: start game....
	{
		requestStackPop();
		return false;
	}



	if (m_uiComponents["SETTINGS"]->isSelected())
		requestStackPush(std::make_unique<SettingsState>(SharedContext{ m_context.m_windowPtr,  m_context.m_texturesPtr, m_context.m_fontsPtr }, m_keyBindingContext, m_stackContext));


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
	auto windowCenterX{ m_context.m_windowPtr->getSize().x / 2.f };
	auto windowCenterY{ m_context.m_windowPtr->getSize().y / 2.f };

	float buttonWidth{ 400.f };
	float buttonHeight{ 65.f };

	// Background
	m_background.setTexture(m_context.m_texturesPtr->getResource("main_menu_background"));
	m_background.setScale({ 1.5f, 1.5f });
	

	// Title
	Label title{ m_context.m_fontsPtr->getResource("main-font"), "SFML RPG Game", { windowCenterX, 100.f }, { 400.f, 65.f } };
	m_uiComponents.insert(std::make_pair("TITLE", std::make_unique<Label>(title)));


	// Start Game Button
	Button playBtn{ m_context.m_fontsPtr->getResource("main-font"), "START GAME", { windowCenterX, 225.f }, { buttonWidth, buttonHeight } };
	m_uiComponents.insert(std::make_pair("START_GAME", std::make_unique<Button>(playBtn)));


	// Settings button
	Button settingsButton{ m_context.m_fontsPtr->getResource("main-font"), "SETTINGS", { windowCenterX, 325.f }, { buttonWidth, buttonHeight } };
	m_uiComponents.insert(std::make_pair("SETTINGS", std::make_unique<Button>(settingsButton)));

	// Quit Button
	Button quitBtn{ m_context.m_fontsPtr->getResource("main-font"), "QUIT GAME", { windowCenterX, 425.f}, { buttonWidth, buttonHeight } };
	m_uiComponents.insert(std::make_pair("QUIT", std::make_unique<Button>(quitBtn)));


}