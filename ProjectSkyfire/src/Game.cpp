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
	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "DankJeWel");
	window->setSize(sf::Vector2u(defaultResolution));
	window->clear();
	window->display();
}

Game::~Game()
{

}

///TODO: Framelock
void Game::run()
{
	initialize();
	
	sf::Event event;
	//double FPS_previous = 0.0;// = double(FPS_clock.restart().asMilliseconds());
	//double FPS_lag = 0.0;
	while (isRunning)
	{
		/*double FPS_current = double(FPS_clock.restart().asMilliseconds());
		double FPS_elapsed = FPS_current - FPS_previous;
		FPS_previous = FPS_current;
		FPS_lag += FPS_elapsed;*/
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
					isRunning = true;
					break;
				default:
					break;
				}
			}
		}
		//std::cout << "Lag: " + std::to_string(FPS_lag) + " :::: MS per update: " + std::to_string(MS_PER_UPDATE) << std::endl;

		//while(FPS_lag >= MS_PER_UPDATE)
		//{
		//	fixedUpdate(event);
		//	FPS_lag -= MS_PER_UPDATE;
		//}
		render();
	}
	std::cout << "Closing...";
}
void Game::initialize()
{
	
	//std::cout << "initializing" << std::endl;
}
void Game::update()
{

	//std::cout << "updating" << std::endl;
}
void Game::fixedUpdate(sf::Event e)
{

	std::cout << "-";
	//std::cout << "updating (fixed)" << std::endl;
}
void Game::render()
{
	window->clear();

	std::cout << "+";

	window->display();
	//std::cout << "rendering" << std::endl;
}
