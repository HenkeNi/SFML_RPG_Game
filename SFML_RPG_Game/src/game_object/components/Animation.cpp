#include "Animation.h"
#include "Rendering.h"

//Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float frameDuration, Rendering* render)
//	: m_imageCount{ imageCount }, m_frameDuration{ frameDuration }, m_totalDuration{ 0.f }, m_renderingComponent{ render }
//{
//	m_currentImage.x = 0;
//
//	m_rect.width = texture->getSize().x / static_cast<float>(imageCount.x);
//	m_rect.height = texture->getSize().y / static_cast<float>(imageCount.y);
//
//}

Animation::Animation(Rendering* render)
	: m_renderingComponent{ render }, m_imageCount{ 3 }, m_totalDuration{ sf::seconds(1.f) }
{
	//auto spriteSize = render->getSize();
	//m_rect.width = spriteSize.width / m_imageCount;
	//m_rect.height = spriteSize.height;
}


#include <iostream>
void Animation::update(sf::Time dt)
{
	if (!m_renderingComponent)
		return;

	static sf::Time timePerFrame = m_totalDuration / static_cast<float>(m_imageCount); // WILL IT WORK WITH OTHER CALLS?? or will it always be the same?!
	m_totalDuration += dt;

	auto spriteSize = m_renderingComponent->getSize();
	int width = spriteSize.x / m_imageCount; // get width of a frame




	if (m_totalDuration >= timePerFrame)
	{ 
		m_totalDuration -= timePerFrame;

		std::cout << m_totalDuration.asSeconds() << ", " << timePerFrame.asSeconds() << '\n';

		//sf::IntRect spriteRect = static_cast<sf::IntRect>(m_renderingComponent->getSize());


		//m_renderingComponent->setTextureRect(sf::IntRect{ 250, 0, 125, 140 });
		//m_renderingComponent->setTextureRect(sf::IntRect{ 0, 0, 125, 140 });

		if (m_currentImage < m_imageCount - 1)
			++m_currentImage;
		else
			m_currentImage = 0;

		std::cout << m_currentImage << '\n';

		//m_renderingComponent->setTextureRect(sf::IntRect{ (int)m_currentImage * 125, 0, 125, 140 });
		//m_renderingComponent->setTextureRect(sf::IntRect{ (int)m_currentImage * width , 0, width, spriteRect.height });
	}
	
	m_renderingComponent->setTextureRect({ (int)m_currentImage * width , 0, width, (int)spriteSize.y });


}


//void Animation::update(sf::Time dt)
//{
//	//sf::Time timePerFrame = m_duration / static_cast<float>(m_numOfFrames);
//	//m_elapsedTime += dt;
//
//	//sf::Vector2i textureBounds{ m_sprite.getTexture()->getSize() };
//	//sf::IntRect textureRect{ m_sprite.getTextureRect() };
//
//	//if (m_currentFrame == 0)
//	//	textureRect = sf::IntRect(0, 0, m_frameSize.x, m_frameSize.y);
//
//	//while (m_elapsedTime >= timePerFrame && (m_currentFrame <= m_numOfFrames || m_shouldRepeat))
//	//{
//	//	// Move texture rect left
//	//	textureRect.left += textureRect.width;
//
//	//	// if reached end of the texture
//	//	if (textureRect.left + textureRect.width > textureBounds.x)
//	//	{
//
//	//	}
//
//	//	mElapsedTime -= timePerFrame;
//	//}
//}





void Animation::updateSprite()
{
	//text.loadFromFile("assets/sprite_sheet/character_idle_down.jpg");
	//player.setTexture(&text);
}




void Animation::setRect(const sf::IntRect& rect)
{
	m_rect = rect;
}


void Animation::restart()
{

}


bool Animation::isFinished() const
{
	return false;
}




