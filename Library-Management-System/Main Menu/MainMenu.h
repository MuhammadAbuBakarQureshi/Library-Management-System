#pragma once

#pragma once
#include <SFML/Graphics.hpp>
#include "../Button/Button.h"

class MainMenu
{
private:

	// Window

	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event evnt;

	// Buttons
	// 
	// Initialization

	void initVariables();
	void initWindow();


public:

	MainMenu();
	~MainMenu();

	void windowLoop();

	void updateTitle();
};
