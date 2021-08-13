#include "SettingsState.h"
#include "../ui_objects/Label.h"


SettingsState::SettingsState(SharedContext context, KeyBinding& keyBindings, StateStack& stack)
	: State{ context, keyBindings, stack }
{
	m_background.setSize(static_cast<sf::Vector2f>(context.m_windowPtr->getSize()));
	m_background.setFillColor({ 94, 10, 11 });

	initUIComponents();
}


void SettingsState::draw()
{
	m_context.m_windowPtr->draw(m_background);

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		m_context.m_windowPtr->draw(*itr->second);
}


bool SettingsState::update(sf::Time dt)
{
	updateMousePositions();

	for (auto itr{ m_uiComponents.begin() }; itr != m_uiComponents.end(); ++itr)
		itr->second->update(m_mousePosView);


	return false;
}


bool SettingsState::handleEvent(const sf::Event& event)
{
	return false;
}


void SettingsState::initUIComponents()
{
	auto windowCenterX{ m_context.m_windowPtr->getSize().x / 2.f };
	auto windowCenterY{ m_context.m_windowPtr->getSize().y / 2.f };

	Label title{ m_context.m_fontsPtr->getResource("main-font"), "Settings", { windowCenterX, 100.f }, { 200.f, 65.f } };
	m_uiComponents.insert(std::make_pair("TITLE", std::make_unique<Label>(title)));
}