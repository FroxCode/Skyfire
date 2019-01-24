#include "systems/CollisionSystem.h"

void CollisionSystem::update()
{
	std::cout << "CollisionSystem update..." << std::endl;
	for (std::vector<Entity*>::iterator i = m_entities.begin(), e = m_entities.end(); i != e; i++)
	{
		for (int j = 0; j < (*i)->getComponents().size(); j++)
		{
			if ((*i)->getComponents().at(j)->getName() == "BoxColliderComponent")
			{
				if ((*i)->getId() == "Example")
				{
					//perform on example entitys BoxColliderComponent
				}
			}
			else if ((*i)->getComponents().at(j)->getName() == "CircleColliderComponent")
			{

			}
		}
	}
}
bool CollisionSystem::checkCollision(sf::Vector2f &point, sf::FloatRect &box)
{
	return box.contains(point);
}
bool CollisionSystem::checkCollision(sf::Vector2f &point, sf::IntRect &box)
{
	sf::Vector2i intVect;
	intVect.x = (int)point.x;
	intVect.y = (int)point.y;
	return box.contains(intVect);
}
bool CollisionSystem::checkCollision(sf::IntRect &a, sf::IntRect &b)
{
	return a.intersects(b);
}
float CollisionSystem::getHorizontalIntersectionDepth(sf::FloatRect &a, sf::FloatRect &b)
{
	float halfWidthA = a.width / 2;
	float halfWidthB = b.width / 2;

	float centerA = a.left + halfWidthA;
	float centerB = b.left + halfWidthB;

	float distanceX = centerA - centerB;
	float minDistanceX = halfWidthA + halfWidthB;

	if (std::abs(distanceX) >= minDistanceX)
	{
		return 0;
	}

	if (distanceX > 0) {
		return minDistanceX - distanceX;
	}
	else
	{
		return -minDistanceX - distanceX;
	}
}
float CollisionSystem::getVerticalIntersectionDepth(sf::FloatRect &a, sf::FloatRect &b)
{
	float halfHeightA = a.height / 2;
	float HalfHeightB = b.height / 2;

	float centerA = a.top + halfHeightA;
	float centerB = b.top + HalfHeightB;

	float distanceY = centerA - centerB;
	float minDistanceY = halfHeightA + HalfHeightB;

	if (std::abs(distanceY) >= minDistanceY)
	{
		return 0;
	}

	if (distanceY > 0) {
		return minDistanceY - distanceY;
	}
	else
	{
		return -minDistanceY - distanceY;
	}
}
sf::FloatRect CollisionSystem::asFloatRect(sf::IntRect &rect)
{
	return sf::FloatRect((float)rect.left, (float)rect.top, (float)rect.width, (float)rect.height);
}