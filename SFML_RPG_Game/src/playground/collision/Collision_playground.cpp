#include "Collision_playground.h"

#include <iostream>

namespace collision_playground
{

	void run()
	{
		sf::RenderWindow window{ sf::VideoMode{960, 540}, "Collision", sf::Style::Close | sf::Style::Resize };

		sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(960, 540));

		Player player{ sf::Vector2f(20.f, 30.f), sf::Vector2f(50.f, 50.f) };
		

		float dt = 0.f;
		sf::Clock clock;

		Platform platform1(sf::Vector2f(200.f, 100.f), sf::Vector2f(400.f, 200.f));
		Platform platform2(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 300.f));


		while (window.isOpen())
		{


			sf::Event event;

			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			player.update(dt);
			view.setCenter(player.getPosition());

			// update before collision
			platform1.getCollider().checkCollision(player.getCollider(), 0.f);
			platform2.getCollider().checkCollision(player.getCollider(), 1.0f);
				
			window.clear(sf::Color::Cyan);

			platform1.draw(window);
			platform2.draw(window);
			player.draw(window);

			window.display();
		}
	}
}