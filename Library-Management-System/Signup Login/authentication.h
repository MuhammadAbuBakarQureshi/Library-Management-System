#pragma once

#include <SFML/Graphics.hpp>

class Authentication {

private:

	sf::RenderWindow* window;
	sf::Event evnt;

public:

	Authentication(sf::RenderWindow*, sf::Event);

	void authenticationOptions();
};