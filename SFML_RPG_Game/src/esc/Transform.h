#pragma once

#include "Component.h"
#include "ComponentTypes.h"

#include <SFML/Graphics.hpp>


class Transform : public Component_esc
{
public:
	Transform();

	void setPosition(const sf::Vector2f& pos);
	void setPosition(float vx, float vy);

	void move(const sf::Vector2f& pos);
	void move(float vx, float vy);

	inline const sf::Vector2f& getPosition() const { return m_position; }
	
	virtual ComponentType getComponentType() const override;
	virtual bool		  init(void* pDescription) override final;

private:
	sf::Vector2f m_position, m_scale;
	float m_rotation;
	//static constexpr ComponentType m_componentType{ ComponentType::TRANSFORM };

};

