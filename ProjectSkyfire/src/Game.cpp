////////////////////////////////////////////////////////////
//
// Game.cpp
// Created by Dale Sinnott
// 17/12/2018
//
////////////////////////////////////////////////////////////
#include "Game.h"
Game::Game()
{
	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "ProjectSkyfire");
	window->setSize(sf::Vector2u(defaultResolution));
	window->clear();
	window->display();
}

Game::~Game()
{

}

///Game loop
void Game::run()
{
	initialize();	
	sf::Event event;
	FPS_clock.restart();
	sf::Int32 FPS_previous = FPS_clock.getElapsedTime().asMilliseconds();
	sf::Int32 FPS_lag = 0;
	while (isRunning)
	{
		sf::Int32 FPS_current = FPS_clock.getElapsedTime().asMilliseconds();
		sf::Int32 FPS_elapsed = FPS_current - FPS_previous;
		FPS_previous = FPS_current;
		FPS_lag += FPS_elapsed;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					isRunning = false;
					break;
				default:
					break;
				}
			}
		}
		while(FPS_lag >= MS_PER_UPDATE)
		{
			fixedUpdate(event);
			
			FPS_lag -= MS_PER_UPDATE;
		}
		render(); //here lag could be passed to advance physics just before rendering (normalized: lag/ms per update)
	}
	std::cout << "Closing...";
}
void Game::initialize()
{
	///std::cout << "initializing" << std::endl;
}
void Game::update()
{
	///std::cout << "updating" << std::endl;
}
void Game::fixedUpdate(sf::Event e)
{
	///std::cout << "updating (fixed)" << std::endl;
}
void Game::render()
{
	///std::cout << "rendering" << std::endl;
	//TODO: update physics before rendering at % towards next fixed update
	window->clear(sf::Color::Black);

	///Draw in here

	window->display();
}
