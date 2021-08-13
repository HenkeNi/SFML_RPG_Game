#include "PauseState.h"
#include "../ui_objects/Button.h"
#include "../ui_objects/Label.h"

PauseState::PauseState(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: State{ context, keyBindings, stack }
{
	m_background.setSize(static_cast<sf::Vector2f>(context.m_windowPtr->getSize()));
	m_background.setFillColor({ 54, 36, 76 });

	initUIComponents();
}


void PauseState::draw()
{
	m_context.m_windowPtr->draw(m_background);

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		m_context.m_windowPtr->draw(*itr->second);
}


bool PauseState::update(sf::Time dt)
{
	updateMousePositions();

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		itr->second->update(m_mousePosView);

	return false;
}


bool PauseState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStackPop(); // Resume the game (un-pause) 

	return false;
}


void PauseState::initUIComponents()
{
	auto windowCenterX{ m_context.m_windowPtr->getSize().x / 2.f };
	auto windowCenterY{ m_context.m_windowPtr->getSize().y / 2.f };

	float buttonWidth{ 400.f };
	float buttonHeight{ 65.f };


	Label title{ m_context.m_fontsPtr->getResource("main-font"), "Paused", { windowCenterX, 100.f }, { 200.f, 65.f } };
	m_uiComponents.insert(std::make_pair("TITLE", std::make_unique<Label>(title)));


	Button quitBtn{ m_context.m_fontsPtr->getResource("main-font"), "QUIT GAME", { windowCenterX, 425.f}, { buttonWidth, buttonHeight } };
	m_uiComponents.insert(std::make_pair("QUIT", std::make_unique<Button>(quitBtn)));
}