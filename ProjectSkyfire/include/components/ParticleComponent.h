////////////////////////////////////////////////////////////
//
// ParticleComponent.h (Data for a particle system to use)
// Created by Dale Sinnott
// 10/01/2019
//
////////////////////////////////////////////////////////////
#ifndef _PARTICLECOMPONENT_H_
#define _PARTICLECOMPONENT_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///Frox
#include "Component.h"


class ParticleComponent : public Component
{
public:
	////////////////////////////////////////////////////////////
	/// Overloaded constructor
	////////////////////////////////////////////////////////////
	ParticleComponent() : Component("ParticleComponent"),
	m_position(0,0), m_velocity(0,0), 
	m_color(sf::Color::White), m_size(10), m_alive(false){}

	////////////////////////////////////////////////////////////
	/// Destructor (for overriding virtual function in abstract 
	/// base Component)
	////////////////////////////////////////////////////////////
	~ParticleComponent() { }

	////////////////////////////////////////////////////////////
	/// Getters/Setters
	////////////////////////////////////////////////////////////
	sf::Vector2f getPosition() { return m_position; }
	void setPosition(sf::Vector2f position) { m_position = position; }

	sf::Vector2f getVelocity() { return m_velocity; }
	void setVelocity(sf::Vector2f velocity) { m_velocity = velocity; }

	sf::Color getColor() { return m_color; }
	void setColor(sf::Vector2f color) { m_color = m_color; }

	float getSize() { return m_size; }
	void setSize(float size) { m_size = size; }

	std::shared_ptr<sf::CircleShape> getParticle() { return m_particle; }
	void setParticle(std::shared_ptr<sf::CircleShape> particle) { m_particle = particle; }

	bool isAlive() { return m_alive; }

private:
	////////////////////////////////////////////////////////////
	/// Member Variables
	////////////////////////////////////////////////////////////
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Color m_color;
	float m_size;
	std::shared_ptr<sf::CircleShape> m_particle;
	bool m_alive;

};
#endif;