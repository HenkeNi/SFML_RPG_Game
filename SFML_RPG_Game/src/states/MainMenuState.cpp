#include "MainMenuState.h"
#include "../ui_objects/Button.h"
#include "../ui_objects/Label.h"
#include "Background.h"
#include "SettingsState.h"

#include <iostream>


MainMenuState::MainMenuState(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: State{ context, keyBindings, stack }
{
	initUIComponents();
	m_buttonPressDelay.restart();
}


void MainMenuState::draw()
{
	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		m_context.m_windowPtr->draw(*itr->second);
}


void MainMenuState::update(sf::Time dt)
{
	updateMousePosition();

	for (const auto& comp : m_uiComponents)
		comp.second->update(m_mousePosView);

		/*if (comp.second->isSelectable() && comp.second->isSelected())
			comp.second->performAction();*/



	// small button press delay when state displayed
	if (m_buttonPressDelay.getElapsedTime() > sf::seconds(0.5f))
	{
		//// FIX: put in function or handle differently (FIX THIS!!!!) PUT IN HANDLEEVENT???
		if (m_uiComponents["START_GAME"]->isSelected())
			requestStackPop();
		else if (m_uiComponents["SETTINGS"]->isSelected())
			requestStackPush(std::make_unique<SettingsState>(m_context, m_keyBindingContext, m_stackContext));
		else if (m_uiComponents["QUIT"]->isSelected())
			m_context.m_windowPtr->close(); // Request clear stack?? stateClear..?
	}	
}


void MainMenuState::handleEvent(const sf::Event& event)
{
	for (const auto& comp : m_uiComponents)
		comp.second->handleEvent(event);
}


void MainMenuState::initUIComponents()
{	
	auto windowCenterX{ m_context.m_windowPtr->getSize().x / 2.f };
	auto windowCenterY{ m_context.m_windowPtr->getSize().y / 2.f };

	float buttonWidth{ 400.f };
	float buttonHeight{ 65.f };

	// Background
	Background background{ m_context.m_texturesPtr->getResource("main_menu_background"), {1.5f, 1.5f} };
	m_uiComponents.insert(std::make_pair("BACKGROUND", std::make_unique<Background>(background)));
	//m_background.setTexture(m_context.m_texturesPtr->getResource("main_menu_background"));
	//m_background.setScale({ 1.5f, 1.5f });
	

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