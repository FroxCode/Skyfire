#include "systems/PhysicsSystem.h"

void PhysicsSystem::update()
{
	std::cout << "PhysicsSystem update..." << std::endl;
	for (std::vector<Entity*>::iterator i = m_entities.begin(), e = m_entities.end(); i != e; i++)
	{
		for (int j = 0; j < (*i)->getComponents().size(); j++)
		{
			if ((*i)->getComponents().at(j)->getName() == "TransformComponent")
			{
				for (int k = 0; k < (*i)->getComponents().size(); k++)
				{
					if ((*i)->getComponents().at(k)->getName() == "VelocityComponent")
					{
						static_cast<TransformComponent*>((*i)->getComponents().at(j))->setPosition(sf::Vector2f(
							(static_cast<TransformComponent*>((*i)->getComponents().at(j))->getPosition().x +
								static_cast<VelocityComponent*>((*i)->getComponents().at(k))->getVelocity().x),
							(static_cast<TransformComponent*>((*i)->getComponents().at(j))->getPosition().y +
								static_cast<VelocityComponent*>((*i)->getComponents().at(k))->getVelocity().y)
						));
					}
					else if ((*i)->getComponents().at(k)->getName() == "GravityComponent")
					{
						static_cast<TransformComponent*>((*i)->getComponents().at(j))->setPosition(sf::Vector2f(
							(static_cast<TransformComponent*>((*i)->getComponents().at(j))->getPosition().x ),
							(static_cast<TransformComponent*>((*i)->getComponents().at(j))->getPosition().y +
								static_cast<GravityComponent*>((*i)->getComponents().at(k))->getGravityAsVec().y)
						));
					}
				}
			}
		}
	}
}