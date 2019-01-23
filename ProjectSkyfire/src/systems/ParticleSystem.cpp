#include"systems/ParticleSystem.h"

void ParticleSystem::update()
{
	///std::cout << "ParticleSystem update..." << std::endl;
	for (std::vector<Entity*>::iterator i = m_entities.begin(), e = m_entities.end(); i != e; i++)
	{
		for (int j = 0; j < (*i)->getComponents().size(); j++)
		{
			if ((*i)->getComponents().at(j)->getName() == "ParticlePoolComponent")
			{
				for (int k = 0; k < ParticlePoolComponent::MAX_PARTICLES; k++)
				{
					if (static_cast<ParticlePoolComponent*>((*i)->getComponents().at(j))->m_pool[k].inUse())
					{
						static_cast<ParticlePoolComponent*>((*i)->getComponents().at(j))->m_pool[k].update();
					}
				}
			}
		}
	}
}
void ParticleSystem::render(std::shared_ptr<sf::RenderWindow> w) 
{
	///std::cout << "ParticleSystem render..." << std::endl;
	for (std::vector<Entity*>::iterator i = m_entities.begin(), e = m_entities.end(); i != e; i++)
	{
		for (int j = 0; j < (*i)->getComponents().size(); j++)
		{
			if ((*i)->getComponents().at(j)->getName() == "ParticlePoolComponent")
			{
				for (int k = 0; k < ParticlePoolComponent::MAX_PARTICLES; k++)
				{
					if (static_cast<ParticlePoolComponent*>((*i)->getComponents().at(j))->m_pool[k].inUse())
					{
						static_cast<ParticlePoolComponent*>((*i)->getComponents().at(j))->m_pool[k].render(w);
					}
				}
			}
		}
	}
}
void ParticleSystem::fuel(int amount, sf::Vector2f position, sf::Vector2f velocity, double radius, sf::Color color)
{
	checkAmount(&amount);
	for (int i = 0; i < amount; i++)
	{
		//...
	}
}
void ParticleSystem::fuelRandom(int amount)
{
	checkAmount(&amount);
	if (amount > 0)
	{
		for (std::vector<Entity*>::iterator i = m_entities.begin(), e = m_entities.end(); i != e; i++)
		{
			for (int j = 0; j < (*i)->getComponents().size(); j++)
			{
				if ((*i)->getComponents().at(j)->getName() == "ParticlePoolComponent")
				{
					for (int k = 0; k < ParticlePoolComponent::MAX_PARTICLES; k++)
					{
						if (!static_cast<ParticlePoolComponent*>((*i)->getComponents().at(j))->m_pool[k].inUse() && amount > 0)
						{
							static_cast<ParticlePoolComponent*>((*i)->getComponents().at(j))->m_pool[k].init(
								sf::Vector2f(randomize(1280), randomize(720)),
								sf::Vector2f(randomize(200, -100), randomize(200, 10)),
								(float)randomize(10, 1),
								sf::Color(255, 255, 255, (sf::Uint8)randomize(100, 10)));
								//sf::Color((sf::Uint8)randomize(255), (sf::Uint8)randomize(255), (sf::Uint8)randomize(255), (sf::Uint8)randomize(255)));
							amount--;
						}
					}
					break;
				}
			}
		}
	}
}
float ParticleSystem::randomize(int max, int min) 
{
	///return max > min ? rand() % max + min : 0;
	return (float)(rand() % max + min);
}	
void ParticleSystem::checkAmount(int *amount)
{
	amount = new int(*amount >= ParticlePoolComponent::MAX_PARTICLES ? ParticlePoolComponent::MAX_PARTICLES - 1 : *amount);
}