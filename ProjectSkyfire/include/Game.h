////////////////////////////////////////////////////////////
//
// Game.h
// Created by Dale Sinnott
// 17/12/2018
//
////////////////////////////////////////////////////////////
#ifndef _GAME_H_
#define _GAME_H_

////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////
///C++
#include <iostream>
#include <memory>

///SFML
#include <SFML/Graphics.hpp>

///Frox
#include "SceneManager.h"
#include "Entity.h"
#include "components/Component.h"
#include "components/BoxColliderComponent.h"
#include "components/CircleColliderComponent.h"
#include "components/GravityComponent.h"
#include "components/ParticleComponent.h"
#include "components/PlayerComponent.h"
#include "components/SoundComponent.h"
#include "components/MusicComponent.h"
#include "components/SpriteComponent.h"
#include "components/TextComponent.h"
#include "components/TransformComponent.h"
#include "components/VelocityComponent.h"



class Game
{
public:
	////////////////////////////////////////////////////////////
	/// Default constructor
	////////////////////////////////////////////////////////////
	Game();

	////////////////////////////////////////////////////////////
	/// Default destructor
	////////////////////////////////////////////////////////////
	~Game();

	////////////////////////////////////////////////////////////
	/// Runs game loop
	////////////////////////////////////////////////////////////
	void run();

private:
	////////////////////////////////////////////////////////////
	/// System Variables
	////////////////////////////////////////////////////////////
	bool isRunning = true;

	std::shared_ptr<sf::RenderWindow> window;
	sf::Vector2i const lowRes = sf::Vector2i(640, 360);
	sf::Vector2i const medRes = sf::Vector2i(1280, 720);
	sf::Vector2i const highRes = sf::Vector2i(1920, 1080);
	sf::Vector2i defaultResolution = medRes;

	Entity testEntity;
	bool playMusic = false;
	bool playSound = false;
	////////////////////////////////////////////////////////////
	/// Member functions
	////////////////////////////////////////////////////////////
	void initialize();
	void update();
	void fixedUpdate();
	void render();
	void musicAction();

};
#endif;