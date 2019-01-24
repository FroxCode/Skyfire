////////////////////////////////////////////////////////////
//
// PhysicsSystem.h
// Created by Dale Sinnott
// 17/12/2018
//
////////////////////////////////////////////////////////////
#ifndef _PHYSICSSYSTEM_H_
#define _PHYSICSSYSTEM_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///SFML
#include <SFML\Graphics.hpp>

///Frox
#include "System.h"
#include "components/TransformComponent.h"
#include "components/GravityComponent.h"
#include "components/VelocityComponent.h"

class PhysicsSystem : public System
{
public:
	void update();

};
#endif;