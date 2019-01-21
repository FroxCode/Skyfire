////////////////////////////////////////////////////////////
//
// ParticlePoolComponent.h (Data pool object for a particle system, particles are colored cirles)
// Created by Dale Sinnott
// 10/01/2019
//
////////////////////////////////////////////////////////////
#ifndef _PARTICLEPOOLCOMPONENT_H_
#define _PARTICLEPOOLCOMPONENT_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///Frox
#include "Component.h"


class ParticlePoolComponent : public Component
{
public:
	friend class ParticlePool;	
	void init(sf::Vector2f position, sf::Vector2f velocity, double radius, sf::Color color)
	{
		m_position = position;
		m_velocity = velocity;
		m_radius = radius;
		m_color = color;
		m_inUse = true;
		setupShape();
	}
	
	bool inUse() { return m_inUse; }
private:
	ParticlePool()
	: m_inUse(false),
	  m_position(0,0),
	  m_velocity(0,0),
	  m_radius(1),
	  m_body(m_radius),
	  m_color(sf::Color(0,0,0))
	{
		m_body.setPosition(m_position);
		m_body.setFillColor(m_color);
	}
	
	bool m_inUse;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::CircleShape m_body;
	double m_radius;
	sf::Color m_color;
	
	void setupShape()
	{
		m_body.setPosition(m_position);
		m_body.setSize(m_radius);
		m_body.setFillColor(m_color);
	}
};
class ParticlePool
{
	Particle m_pool[100];
}
#endif;
