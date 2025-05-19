#pragma once
#include <SFML/Graphics.hpp>

class Window {

private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event evnt;

	void initVariables();
	void initWindow();

public:

	Window();
	~Window();
	
	void windowLoop();

};