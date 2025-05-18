#include "MainMenu.h"

#include <sstream>

#include <iostream>

using namespace std;


void MainMenu::initVariables()
{
    this->window = nullptr;

    // Init Window size

    this->video_mode.height = 800;
    this->video_mode.width = 1000;

}

void MainMenu::initWindow()
{
    this->window = new sf::RenderWindow(this->video_mode, "Snake Glide", sf::Style::Close | sf::Style::Fullscreen);
    this->window->setFramerateLimit(30);
    this->window->setVerticalSyncEnabled(true);

}



MainMenu::MainMenu()
{

    initVariables();
    initWindow();
}

MainMenu::~MainMenu()
{
    delete this->window;
}

void MainMenu::windowLoop()
{
    sf::Color button_color = sf::Color(10, 10, 50);
    sf::Color text_color = sf::Color(192, 192, 192);

    Button start_game("Start Game");
    start_game.setColors(sf::Color(button_color), sf::Color(text_color));
    start_game.setButtonPosition(sf::Vector2f(370, 230));
    start_game.setTextPosition(sf::Vector2f(430, 255));

    Button high_score("High Scores");
    high_score.setColors(sf::Color(button_color), sf::Color(text_color));
    high_score.setButtonPosition(sf::Vector2f(370, 400));
    high_score.setTextPosition(sf::Vector2f(450, 425));

    Button exit("Exit");
    exit.setColors(sf::Color(button_color), sf::Color(text_color));
    exit.setButtonPosition(sf::Vector2f(370, 570));
    exit.setTextPosition(sf::Vector2f(490, 595));

    while (this->window->isOpen()) {

        while (this->window->pollEvent(evnt)) {

            switch (evnt.type) {

            case sf::Event::Closed:

                this->window->close();
                break;
            }
        }

        if (start_game.isClick(*window, evnt)) {

            this->window->close();
        }

        if (high_score.isClick(*window, evnt)) {

            this->window->close();
        }

        if (exit.isClick(*window, evnt)) {

            this->window->close();
        }

        this->window->clear(sf::Color(0, 31, 63));
        updateTitle();
        start_game.render(*window);
        high_score.render(*window);
        exit.render(*window);
        this->window->display();
    }
}

void MainMenu::updateTitle()
{
    sf::Text text;

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    /*cout << desktop.height << "\t" << desktop.width << endl;*/

    int width = desktop.width / 4;

    cout << width << endl;

    text.move(width, 100);

    sf::Font font;

    font.loadFromFile("Fonts/arial.ttf");

    text.setFont(font);

    text.setString("Library Management System");

    text.setCharacterSize(40);

    text.setFillColor(sf::Color(255, 255, 0));

    text.setStyle(sf::Text::Bold);

    window->draw(text);
}