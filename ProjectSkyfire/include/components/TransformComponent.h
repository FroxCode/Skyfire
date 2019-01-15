////////////////////////////////////////////////////////////
//
// TransformComponent.h (Simple 2D coords, 1 axis rotation, x+y scaling)
// Created by Dale Sinnott
// 08/01/2019
//
////////////////////////////////////////////////////////////
#ifndef _TRANSFORMCOMPONENT_H_
#define _TRANSFORMCOMPONENT_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///Frox
#include "Component.h"

///SFML
#include"SFML/Graphics/Transform.hpp"

class TransformComponent : public Component
{
public:
	////////////////////////////////////////////////////////////
	/// Overloaded constructor
	////////////////////////////////////////////////////////////
	TransformComponent(sf::Vector2f position = sf::Vector2f(0.f, 0.f), float rotation = 0.f, 
		sf::Vector2f scale = sf::Vector2f(1.f,1.f)) : Component("TransformComponent"),
		m_position(position), m_rotation(rotation), m_scale(scale) {}

	////////////////////////////////////////////////////////////
	/// Destructor (for overriding virtual function in abstract 
	/// base Component)
	////////////////////////////////////////////////////////////
	~TransformComponent() { }

	////////////////////////////////////////////////////////////
	/// Getters/Setters
	////////////////////////////////////////////////////////////
	void setPosition(sf::Vector2f position) { m_position = position; }
	sf::Vector2f getPosition() { return m_position; }

	void setRotation(float rotation) { m_rotation = rotation; }
	float getRotation() { return m_rotation; }

	void setScale(sf::Vector2f scale) { m_scale = scale; }
	sf::Vector2f getScale() { return m_scale; }

private:
	////////////////////////////////////////////////////////////
	/// Member Variables
	////////////////////////////////////////////////////////////
	sf::Vector2f m_position;
	float m_rotation;
	sf::Vector2f m_scale;

};
#endif;