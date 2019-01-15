////////////////////////////////////////////////////////////
//
// SpriteComponent.h (Simple 2D sprite)
// Created by Dale Sinnott
// 10/01/2019
//
////////////////////////////////////////////////////////////
#ifndef _SPRITECOMPONENT_H_
#define _SPRITECOMPONENT_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///Frox
#include "Component.h"

///SFML
#include"SFML/Graphics.hpp"

class SpriteComponent : public Component
{
public:
	////////////////////////////////////////////////////////////
	/// Overloaded constructor
	////////////////////////////////////////////////////////////
	SpriteComponent(std::string texturePath = "assets/sprites/error.png") : Component("SpriteComponent"),
		m_texturePath(texturePath)
	{
		loadSprite();
	}

	////////////////////////////////////////////////////////////
	/// Destructor (for overriding virtual function in abstract 
	/// base Component)
	////////////////////////////////////////////////////////////
	~SpriteComponent() { }

	////////////////////////////////////////////////////////////
	/// Getters/Setters
	////////////////////////////////////////////////////////////
	void setTexturePath(std::string texturePath) { m_texturePath = texturePath; }
	std::string getTexturePath() { return m_texturePath; }

	void setTexture(std::shared_ptr<sf::Texture> texture) { m_texture = texture; }
	std::shared_ptr<sf::Texture> getTexture() { return m_texture; }

	void setSprite(std::shared_ptr<sf::Sprite> sprite) { m_sprite = sprite; }
	std::shared_ptr<sf::Sprite> getSprite() { return m_sprite; }

	void loadSprite()
	{
		m_sprite = std::make_shared<sf::Sprite>();
		m_texture = std::make_shared<sf::Texture>();
		if (!m_texture->loadFromFile(m_texturePath))
		{
			std::cout << "Unknown error occured loading file: " 
				+ m_texturePath << std::endl;
		}
		else 
		{
			m_sprite->setTexture(*m_texture);
		}
	}
private:
	////////////////////////////////////////////////////////////
	/// Member Variables
	////////////////////////////////////////////////////////////
	std::shared_ptr<sf::Sprite> m_sprite;
	std::shared_ptr<sf::Texture> m_texture;
	std::string m_texturePath;

};
#endif;