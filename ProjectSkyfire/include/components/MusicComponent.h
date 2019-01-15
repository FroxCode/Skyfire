////////////////////////////////////////////////////////////
//
// MusicComponent.h (Basic music container)
// Created by Dale Sinnott
// 10/01/2019
//
////////////////////////////////////////////////////////////
#ifndef _MUSICCOMPONENT_H_
#define _MUSICCOMPONENT_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///Frox
#include "Component.h"

///SFML
#include"SFML/Audio.hpp"

class MusicComponent : public Component
{
public:
	////////////////////////////////////////////////////////////
	/// Overloaded constructor
	////////////////////////////////////////////////////////////
	MusicComponent(std::string musicPath = "assets/sounds/music/music.wav")
		: Component("MusicComponent"),
		m_musicPath(musicPath)
	{
		loadMusic();
	}

	////////////////////////////////////////////////////////////
	/// Destructor (for overriding virtual function in abstract 
	/// base Component)
	////////////////////////////////////////////////////////////
	~MusicComponent() { }

	////////////////////////////////////////////////////////////
	/// Getters/Setters
	////////////////////////////////////////////////////////////
	void setMusic(std::shared_ptr<sf::Music> music) { m_music = music; }
	std::shared_ptr<sf::Music> getMusic() { return m_music; }

	void setMusicPath(std::string musicPath) { m_musicPath = musicPath; }
	std::string getMusicPath() { return m_musicPath; }

	void loadMusic()
	{
		m_music = std::make_shared<sf::Music>();
		if (!m_music->openFromFile(m_musicPath))
		{
			std::cout << "Unknown error occured loading file: "
				+ m_musicPath << std::endl;
		}
	}

private:
	////////////////////////////////////////////////////////////
	/// Member Variables
	////////////////////////////////////////////////////////////
	std::shared_ptr<sf::Music> m_music;
	std::string m_musicPath;

};
#endif;