#pragma once
#include <string>
#include <SFML/Graphics.hpp>


class SignUp {

public:

	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event evnt;

	SignUp(sf::RenderWindow*, sf::VideoMode, sf::Event);

	void renderSignupForm();
};