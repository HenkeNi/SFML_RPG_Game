#include "Animation_playground.h"

namespace animation_playground
{


	Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float frameDuration)
		: m_imageCount{ imageCount }, m_frameDuration{ frameDuration }, m_totalDuration{ 0.f }
	{
		m_currentImage.x = 0;

		m_rect.width = texture->getSize().x / static_cast<float>(imageCount.x);
		m_rect.height = texture->getSize().y / static_cast<float>(imageCount.y);

	}




	void Animation::update(float dt, int row)
	{
		m_currentImage.y = row;
		m_totalDuration += dt;

		if (m_totalDuration >= m_frameDuration)
		{
			m_totalDuration -= m_frameDuration;
			++m_currentImage.x;

			if (m_currentImage.x >= m_imageCount.x)
			{
				m_currentImage.x = 0;
			}
		}
		m_rect.left = m_currentImage.x * m_rect.width;
		m_rect.top = m_currentImage.y * m_rect.height;

		
	}

	void Animation::restart()
	{

	}

	bool Animation::isFinished() const
	{
		return false;
	}
	



	void run()
	{
		sf::RenderWindow window{ sf::VideoMode{512, 512}, "ANimation", sf::Style::Close | sf::Style::Resize };

		sf::RectangleShape player{ sf::Vector2f(150.f, 200.f) };
		player.setPosition(0.f, 0.f);


		sf::Texture text;
		//text.loadFromFile("assets/sprite_sheet/anim_idle.jpg");
		//text.loadFromFile("assets/sprite_sheet/character_idle_down.jpg");
		text.loadFromFile("assets/textures/sheet_idle.png");
		player.setTexture(&text);

		//player.setTextureRect({ 0,0,74,86 });
		Animation anim{ &text, sf::Vector2u{3, 1}, 0.3f };
		//Animation anim{ &text, sf::Vector2u{9, 4}, 0.3f };

		float dt = 0.f;
		sf::Clock clock;

		while (window.isOpen())
		{

			dt = clock.restart().asSeconds();

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


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				;



			anim.update(dt, 0);

			//player.setTextureRect({ 0, 0, 32, 32 });
			player.setTextureRect(anim.getRect());

			window.clear(sf::Color::Cyan);
			window.draw(player);
			window.display();
		}
	}

};