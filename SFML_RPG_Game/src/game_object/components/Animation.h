#pragma once

#include "Component.h"

#include <SFML/Graphics.hpp>
#include <map>


class Rendering;

class Animation : public Component
{
public:
	enum class Animation_State
	{
		Idle_Left, Idle_Right, Idle_Up, Idle_Down, Walking_Left, Walking_Right, Walking_Up, Walking_Down
	};

public:
	//Animation(sf::Texture* texture, sf::Vector2u imageCount, float frameDuration);
	Animation(Rendering* render = nullptr, sf::Vector2u frameSize = sf::Vector2u(0, 0));



	/*void setImageCount();
	void setTotalDuration();*/

	void setCurrentFrameRow(int row);



	//void update(float dt);
	virtual void update(sf::Time dt) override;
	virtual void handleEvent(const sf::Event& event) override; 


	// TEST
	void updateSprite();

	void setRect(const sf::IntRect& rect);

	void restart();
	bool isFinished() const;

	inline const sf::IntRect& getRect() const { return m_rect; }

private:
	Rendering* m_renderingComponent; // make friend class instead??
	sf::IntRect		m_rect;

	//sf::Time	 m_duration; // TODO: Make Frame class/struct -> contains width and height and frame duration??
	//sf::Time     m_elapsedTime;
	//int			 m_numOfFrames;
	//int			 m_currentFrame;
	//sf::Vector2i m_frameSize;
	//bool         m_shouldRepeat;


	//sf::Sprite m_sprite;	// use reference instead?

	//std::map<std::string, sf::Texture> m_textureSheet;
		

	// MULTI ARRAY OVER HOW THE SPRITES ARE LAID OUT (HOW MANY PER ROW...)



	sf::Vector2u m_frameSize;
	sf::Vector2u m_currentFrame;

	//unsigned int m_imageCount; // number of frames in animation  TODO: rename?? numOfFrames??
	//unsigned int m_currentImage{ 0 }; // the current frame in sequence


	sf::Time m_totalDuration;
	//float m_frameDuration; // time before it switches to next image

};
