#include "window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Signup Login/Signup.h"
#include "../Signup Login/authentication.h"



void Window::initVariables() {

	this->window = nullptr;

	sf::VideoMode desktopScreen = sf::VideoMode::getDesktopMode();

	this->videoMode.height = desktopScreen.height;
	this->videoMode.width = desktopScreen.width;	
}

void Window::initWindow() {

	this->window = new sf::RenderWindow(this->videoMode, "Library Mangement System", sf::Style::Close);
}

Window::Window() {

	initVariables();
	initWindow();
}

Window::~Window() {

	delete this->window;
}

void Window::windowLoop() {

	while (this->window->isOpen()) {

		while (this->window->pollEvent(evnt)) {

			switch (evnt.type)
			{
			case sf::Event::Closed:

				this->window->close();
				break;
			}

			Authentication authentication(this->window, this->evnt);
			authentication.authenticationOptions();

		}
	}
}