#include "PauseState.h"
#include "../ui_objects/Button.h"
#include "../ui_objects/Label.h"
#include "../Constants.h"
#include "MainMenuState.h"

#include <iostream>

PauseState::PauseState(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: State{ context, keyBindings, stack }
{
	m_background.setSize(static_cast<sf::Vector2f>(context.m_windowPtr->getSize()));
	m_background.setFillColor({ 54, 36, 76 });

	initUIComponents();
	m_context.m_windowPtr->setView(sf::View({ constants::SCR_WIDTH / 2, constants::SCR_HEIGHT / 2 }, { constants::SCR_WIDTH, constants::SCR_HEIGHT }));
}


void PauseState::draw()
{
	m_context.m_windowPtr->draw(m_background);

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		m_context.m_windowPtr->draw(*itr->second);
}


void PauseState::update(sf::Time dt)
{
	updateMousePosition();

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		itr->second->update(m_mousePosView);


	if (m_uiComponents["RESUME"]->isSelected())
		m_popState = true;
		//requestStackPop();

	if (m_uiComponents["MENU"]->isSelected())
	{
		// TODO: Pop pause State?? - seems to be working regardless...!?

		//requestStackPop();
		requestStackPush(std::make_unique<MainMenuState>(m_context, m_keyBindingContext, m_stackContext));

		//return;
	}

	if (m_uiComponents["QUIT"]->isSelected())
		m_context.m_windowPtr->close();

	if (m_popState)
		requestStackPop();
}


void PauseState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		m_popState = true;
		//requestStackPop(); // Resume the game (un-pause) 
	
	
}


void PauseState::initUIComponents()
{
	auto windowCenterX{ m_context.m_windowPtr->getSize().x / 2.f };
	auto windowCenterY{ m_context.m_windowPtr->getSize().y / 2.f };

	float buttonWidth{ 400.f };
	float buttonHeight{ 65.f };


	Label title{ m_context.m_fontsPtr->getResource("main-font"), "Paused", { windowCenterX, 100.f }, { 200.f, 65.f } };
	m_uiComponents.insert(std::make_pair("TITLE", std::make_unique<Label>(title)));

	Button resumeBtn{ m_context.m_fontsPtr->getResource("main-font"), "RESUME", { windowCenterX, 225.f}, { buttonWidth, buttonHeight } };
	m_uiComponents.insert(std::make_pair("RESUME", std::make_unique<Button>(resumeBtn)));

	Button mainMenuBtn{ m_context.m_fontsPtr->getResource("main-font"), "MAIN MENU", { windowCenterX, 325.f}, { buttonWidth, buttonHeight } };
	m_uiComponents.insert(std::make_pair("MENU", std::make_unique<Button>(mainMenuBtn)));

	Button quitBtn{ m_context.m_fontsPtr->getResource("main-font"), "QUIT GAME", { windowCenterX, 425.f}, { buttonWidth, buttonHeight } };
	m_uiComponents.insert(std::make_pair("QUIT", std::make_unique<Button>(quitBtn)));
}