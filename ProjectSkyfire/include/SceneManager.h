////////////////////////////////////////////////////////////
//
// Created by Dale Sinnott
//
////////////////////////////////////////////////////////////
#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML\Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#include "scenes/Scene.h"
#include "scenes/MenuScene.h"
#include "scenes/GameScene.h"

class SceneManager
{
public:
	////////////////////////////////////////////////////////////
	/// Default constructor
	///
	////////////////////////////////////////////////////////////
	SceneManager();

	////////////////////////////////////////////////////////////
	/// Default destructor
	///
	////////////////////////////////////////////////////////////
	~SceneManager();

	void fixedUpdate();
	void update();
	void render(std::shared_ptr<sf::RenderWindow> window);
	void setScene(std::string targetSceneName);
	std::string currentScene;
	std::shared_ptr<sf::RenderWindow> window;
	std::vector<std::shared_ptr<Scene>> scenes;
	void initialise(std::shared_ptr<sf::RenderWindow> w);
	//std::shared_ptr<GameData> m_data;

private:
	int globalVolumeSFX;
	int globalVolumeMusic;
	std::shared_ptr<MenuScene> menuScene;
	std::shared_ptr<sf::Shader> constantShader;
};
#endif;