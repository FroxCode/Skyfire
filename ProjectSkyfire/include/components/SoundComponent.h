////////////////////////////////////////////////////////////
//
// SoundComponent.h (Basic sound fx container)
// Created by Dale Sinnott
// 10/01/2019
//
////////////////////////////////////////////////////////////
#ifndef _SOUNDCOMPONENT_H_
#define _SOUNDCOMPONENT_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///Frox
#include "Component.h"

///SFML
#include"SFML/Audio.hpp"

class SoundComponent : public Component
{
public:
	////////////////////////////////////////////////////////////
	/// Overloaded constructor
	////////////////////////////////////////////////////////////
	SoundComponent(std::string soundPath = "assets/sounds/SFX/default.wav")
		: Component("SoundComponent"),
		m_soundPath(soundPath)
	{
		loadSound();
	}

	////////////////////////////////////////////////////////////
	/// Destructor (for overriding virtual function in abstract 
	/// base Component)
	////////////////////////////////////////////////////////////
	~SoundComponent() { }

	////////////////////////////////////////////////////////////
	/// Getters/Setters
	////////////////////////////////////////////////////////////
	void setBuffer(std::shared_ptr<sf::SoundBuffer> buffer) { m_buffer = buffer; }
	std::shared_ptr<sf::SoundBuffer> getBuffer() { return m_buffer; }

	void setSound(std::shared_ptr<sf::Sound> sound) { m_sound = sound; }
	std::shared_ptr<sf::Sound> getSound() { return m_sound; }

	void setSoundPath(std::string soundPath) { m_soundPath = soundPath; }
	std::string getSoundPath() { return m_soundPath; }

	void loadSound()
	{
		m_buffer = std::make_shared<sf::SoundBuffer>();
		m_sound = std::make_shared<sf::Sound>();

		if (!m_buffer->loadFromFile(m_soundPath))
		{
			std::cout << "Unknown error occured loading file: "
				+ m_soundPath << std::endl;
		}
		else
		{
			m_sound->setBuffer(*m_buffer);
		}
	}

private:
	////////////////////////////////////////////////////////////
	/// Member Variables
	////////////////////////////////////////////////////////////
	std::shared_ptr<sf::Sound> m_sound;
	std::shared_ptr<sf::SoundBuffer> m_buffer;
	std::string m_soundPath;

};
#endif;