#include "authentication.h"

#include "../Button/Button.h"

#include "../Signup Login/Signup.h"

#include <iostream>

Authentication::Authentication(sf::RenderWindow* window, sf::Event evnt) {

	this->window = window;
	this->evnt = evnt;
}

void Authentication::authenticationOptions()
{

	sf::Color button_color = sf::Color(10, 10, 50);
	sf::Color text_color = sf::Color(192, 192, 192);

	Button signUp("Sign Up");
	signUp.setColors(sf::Color(button_color), sf::Color(text_color));
	signUp.setButtonPosition(sf::Vector2f(370, 230));
	signUp.setTextPosition(sf::Vector2f(430, 255));

	Button login("Login");
	login.setColors(sf::Color(button_color), sf::Color(text_color));
	login.setButtonPosition(sf::Vector2f(370, 530));
	login.setTextPosition(sf::Vector2f(430, 555));

	bool isAuthenticate = false;

	while (!isAuthenticate) {

		while (this->window->pollEvent(this->evnt)) {

			switch (this->evnt.type)
			{
			case sf::Event::Closed:
				
				this->window->close();
				isAuthenticate = true;
				break;

			default:
				break;
			}
		}

		if (signUp.isClick(*this->window, this->evnt)) {

			SignUp userSignUp(this->window, this->evnt);
			userSignUp.renderSignupForm();
		}

		if (login.isClick(*this->window, this->evnt)) {

			cout << "Login" << endl;
		}
		
		this->window->clear(sf::Color(0, 31, 63));

		signUp.render(*this->window);
		login.render(*this->window);

		this->window->display();
	}
}
