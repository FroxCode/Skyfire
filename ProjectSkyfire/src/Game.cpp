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
	
	while (isRunning)
	{
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
				case sf::Keyboard::Space:
					playSound = true;
					break;
				case sf::Keyboard::Enter:
					musicAction();
					break;
				default:
					break;
				}
			}
		}
		//TODO: Encapsulate in frame lock
		update();
		render();
	}
	std::cout << "Closing...";
}
void Game::musicAction()
{
	playMusic = !playMusic;
	for (int i = 0; i < testEntity.getComponents().size(); i++)
	{
		if (testEntity.getComponents().at(i)->getName() == "MusicComponent") {
			switch (playMusic)
			{
			case true:
				static_cast<MusicComponent*>(testEntity.getComponents().at(i))->getMusic()->play();
				break;
			case false:
				static_cast<MusicComponent*>(testEntity.getComponents().at(i))->getMusic()->pause();
				break;
			default:
				break;
			}
		}
	}
}
void Game::initialize()
{
	std::cout << "initializing" << std::endl;
	testEntity.addComponent(new SoundComponent());

	testEntity.addComponent(new MusicComponent());
	//testEntity.addComponent(new SpriteComponent("assets/sprites/test.png"));
	/*for (int i = 0; i < testEntity.getComponents().size(); i++)
	{
		if (testEntity.getComponents().at(i)->getName() == "SpriteComponent")
		{
			static_cast<SpriteComponent*>(testEntity.getComponents().at(i))->getSprite()->setOrigin(
				static_cast<SpriteComponent*>(testEntity.getComponents().at(i))->getSprite()->getLocalBounds().width / 2,
				static_cast<SpriteComponent*>(testEntity.getComponents().at(i))->getSprite()->getLocalBounds().height / 2
			);
			static_cast<SpriteComponent*>(testEntity.getComponents().at(i))->getSprite()->setPosition(200, 200);
		}
	}*/

}
void Game::update()
{
	if (playSound)
	{
		playSound = false;	
		for (int i = 0; i < testEntity.getComponents().size(); i++)
		{
			if (testEntity.getComponents().at(i)->getName() == "SoundComponent") {
				static_cast<SoundComponent*>(testEntity.getComponents().at(i))->getSound()->play();
			}
		}

	}

	/*for (int i = 0; i < testEntity.getComponents().size(); i++)
	{
		if (testEntity.getComponents().at(i)->getName() == "SpriteComponent")
		{
			static_cast<SpriteComponent*>(testEntity.getComponents().at(i))->getSprite()->setRotation(
				static_cast<SpriteComponent*>(testEntity.getComponents().at(i))->getSprite()->getRotation() + 1);
		}
	}*/

	//std::cout << "updating" << std::endl;
}
void Game::fixedUpdate()
{
	//std::cout << "updating (fixed)" << std::endl;
}
void Game::render()
{
	window->clear();
	/*for (int i = 0; i < testEntity.getComponents().size(); i++)
	{
		if (testEntity.getComponents().at(i)->getName() == "SpriteComponent")
		{
			window->draw(*static_cast<SpriteComponent*>(testEntity.getComponents().at(i))->getSprite());
		}
	}*/
	window->display();
	//std::cout << "rendering" << std::endl;
}
