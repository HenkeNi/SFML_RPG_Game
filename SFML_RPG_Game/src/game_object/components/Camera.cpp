#include "Camera.h"
#include "Movement.h"
#include "../Constants.h"

#include <iostream>

Camera::Camera(sf::RenderWindow& window, Movement* movement)
	: m_window{ window }, m_movement{ movement }, m_view{ sf::View{{0.f, 0.f}, { constants::VIEW_HEIGHT, constants::VIEW_HEIGHT  }}}
{
		// m_view = sf::View(sf::Vector2f{ 0.f, 0.f }, sf::Vector2f{ constants::SCR_WIDTH, constants::SCR_HEIGHT });
}


void Camera::update(sf::Time dt)
{
	// set view after players position...??!


	updateViewPos();

	m_window.setView(m_view);
}



void Camera::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::Resized)
		resizeView();
}



// If slight delay when camera is moving.. make sure movement is done first??
void Camera::updateViewPos()
{
	if (!m_movement)
		return;

	//m_view.setCenter(m_movement->getVelocity());

	std::cout << "Velocity: " << m_movement->getVelocity().x << ", " << m_movement->getVelocity().y << '\n';

	auto velocity{ m_movement->getVelocity() };
	sf::Vector2f cameraPos = velocity;

	// TODO: fix camera not showing "out of bounds"
	if (velocity.x - (constants::SCR_WIDTH / 2) < 0.f)
		cameraPos.x = constants::SCR_WIDTH / 2 - 75;
	if (velocity.y - (constants::SCR_HEIGHT / 2) < 0.f)
		cameraPos.y = constants::SCR_HEIGHT / 2;


	//if (velocity.x < 0.f)
	//	cameraPos.x = 0.f;
	//if (velocity.y < 0.f)
	//	cameraPos.y = 0.f;


	m_view.setCenter(cameraPos);
}


void Camera::resizeView()
{
	float aspectRatio{ static_cast<float>(m_window.getSize().x) / static_cast<float>(m_window.getSize().y) };
	m_view.setSize(constants::VIEW_HEIGHT * aspectRatio, constants::VIEW_HEIGHT);
}