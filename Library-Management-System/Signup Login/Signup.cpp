#include "Signup.h"
#include <SFML/Graphics.hpp>
#include "../Button/Button.h"

// Constructor

SignUp::SignUp(sf::RenderWindow* window, sf::VideoMode video_mode, sf::Event evnt) {

	this->window = window;
	this->video_mode = video_mode;
	this->evnt = evnt;
}

void SignUp::renderSignupForm() {


	sf::Color button_color = sf::Color(10, 10, 50);
	sf::Color text_color = sf::Color(192, 192, 192);

	Button signUp("Sign Up");
	signUp.setColors(sf::Color(button_color), sf::Color(text_color));
	signUp.setButtonPosition(sf::Vector2f(370, 230));
	signUp.setTextPosition(sf::Vector2f(430, 255));

	bool isRegistered = true;

	while (isRegistered) {
	
		while (this->window->pollEvent(evnt)) {

			switch (evnt.type)
			{
			
			case sf::Event::Closed:

				this->window->close();
				isRegistered = false;
				break;
			}

		}


		if (signUp.isClick(*window, evnt)) {

			this->window->close();
			isRegistered = false;
		}

		this->window->clear(sf::Color(0, 31, 63));
		signUp.render(*window);
		this->window->display();
	}
}