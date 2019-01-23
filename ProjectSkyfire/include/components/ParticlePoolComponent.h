////////////////////////////////////////////////////////////
//
// !!!!!!!!!!EXTREMELY EXPERIMENTAL!!!!!!!!!!!!!
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
class Particle
{
	friend class ParticlePoolComponent;

public:
	void init(sf::Vector2f position, sf::Vector2f velocity, float radius, sf::Color color)
	{
		///std::cout << "Creating particle from object pool..." << std::endl;	
		m_position = position;
		m_velocity = velocity;
		m_radius = radius;
		m_color = color;
		m_alpha = color.a;
		m_inUse = true;
		setupShape();
	}
	void update() {
		m_position += (m_velocity * FPS);
		m_body.setPosition(m_position);
		m_body.setFillColor(sf::Color(m_body.getFillColor().r,
			m_body.getFillColor().g,
			m_body.getFillColor().b,
			m_alpha--));
		if (m_alpha <= 1)
		{
			m_inUse = false;
		}
	}
	void render(std::shared_ptr<sf::RenderWindow> w) {
		
		w->draw(m_body);
	}

	bool inUse() { return m_inUse; }
private:
	float const FPS = 1.f / 60.f;
	Particle() :
		m_inUse(false),
		m_position(0.f, 0.f),
		m_velocity(0.f, 0.f),
		m_radius(1.f),
		m_body(m_radius),
		m_color(sf::Color(0, 0, 0)),
		m_alpha(0)
	{
		m_body.setPosition(m_position);
		m_body.setFillColor(m_color);
	}

	bool m_inUse;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::CircleShape m_body;
	float m_radius;
	sf::Color m_color;
	int m_alpha;

	void setupShape()
	{
		m_body.setPosition(m_position);
		m_body.setRadius(m_radius);
		m_body.setFillColor(m_color);
	}

};
class ParticlePoolComponent : public Component
{
public:
	ParticlePoolComponent() : Component("ParticlePoolComponent") { std::cout << "ParticlePool Created" << std::endl; }
	static int const MAX_PARTICLES = 400;
	Particle m_pool[MAX_PARTICLES];
	~ParticlePoolComponent() { }
};
#endif;