#pragma once

#include <SFML/Graphics.hpp>

namespace animation_playground
{
	class Animation
	{
	public:
		Animation(sf::Texture* texture, sf::Vector2u imageCount, float frameDuration);
		void update(float dt, int row);

		void restart();
		bool isFinished() const;

		inline const sf::IntRect& getRect() const { return m_rect; }

	private:
		sf::IntRect m_rect;

		sf::Vector2u m_imageCount; // number of frames in animation
		sf::Vector2u m_currentImage; // the current frame in sequence


		float m_totalDuration;
		float m_frameDuration; // time before it switches to next image
	};
	

	void run();

}

