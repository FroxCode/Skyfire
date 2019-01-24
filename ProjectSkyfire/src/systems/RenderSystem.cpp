#include "systems/RenderSystem.h"

void RenderSystem::update(std::shared_ptr<sf::RenderWindow> w)
{
	std::cout << "RenderSystem update..." << std::endl;
	for (std::vector<Entity*>::iterator i = m_entities.begin(), e = m_entities.end(); i != e; i++)
	{
		for (int j = 0; j < (*i)->getComponents().size(); j++)
		{
			if ((*i)->getComponents().at(j)->getName() == "SpriteComponent")
			{
				for (int k = 0; k < (*i)->getComponents().size(); k++)
				{
					if ((*i)->getComponents().at(j)->getName() == "TransformComponent")
					{
						static_cast<SpriteComponent*>((*i)->getComponents().at(j))->getSprite()->setPosition(
							static_cast<TransformComponent*>((*i)->getComponents().at(j))->getPosition());
					}
				}///update sprite position before draw
				w->draw(*static_cast<SpriteComponent*>((*i)->getComponents().at(j))->getSprite());
			}
		}
	}
}