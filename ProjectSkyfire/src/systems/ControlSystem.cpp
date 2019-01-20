#include "systems/ControlSystem.h"

void ControlSystem::update(sf::Event e)
{
	std::cout << "ControlSystem update..." << std::endl;
	for (std::vector<Entity*>::iterator i = m_entities.begin(), e = m_entities.end(); i != e; i++)
	{
		//Would need a control list (game specific)
		//add velocity to players VelocityComponent. Physics/graphics should sort the rest
		//if player has no vel component, try move it manually via TransformComponent?

		///TODO: Implementation of Command pattern
	}
}