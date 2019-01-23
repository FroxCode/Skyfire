////////////////////////////////////////////////////////////
//
// ParticleSystem.h
// Created by Dale Sinnott
// 17/12/2018
//
////////////////////////////////////////////////////////////
#ifndef _PARTICLESYSTEM_H_
#define _PARTICLESYSTEM_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///SFML
#include <SFML\Graphics.hpp>

///Frox
#include "System.h"
#include "components/ParticlePoolComponent.h"

class ParticleSystem : public System
{
public:

	ParticleSystem() : System() {}
	~ParticleSystem() {}
	void update();
	void fuel(int amount, sf::Vector2f position, sf::Vector2f velocity, double radius, sf::Color color);
	void fuelRandom(int amount);
	void checkAmount(int* amount);
	void render(std::shared_ptr<sf::RenderWindow> w);
	float randomize(int max, int min = 0);

};
#endif;