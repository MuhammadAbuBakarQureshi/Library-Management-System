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

    Button all_books("All Books");
    all_books.setColors(sf::Color(button_color), sf::Color(text_color));
    all_books.setButtonPosition(sf::Vector2f(370, 230));
    all_books.setTextPosition(sf::Vector2f(430, 255));

    Button search_book("Search Book");
    search_book.setColors(sf::Color(button_color), sf::Color(text_color));
    search_book.setButtonPosition(sf::Vector2f(370, 400));
    search_book.setTextPosition(sf::Vector2f(450, 425));

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

        if (all_books.isClick(*window, evnt)) {

            this->window->close();
        }

        if (search_book.isClick(*window, evnt)) {

            this->window->close();
        }

        if (exit.isClick(*window, evnt)) {

            this->window->close();
        }

        this->window->clear(sf::Color(0, 31, 63));
        updateTitle();
        all_books.render(*window);
        search_book.render(*window);
        exit.render(*window);
        this->window->display();
    }
}

void MainMenu::updateTitle()
{
    sf::Text text;

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    int width = desktop.width / 4;

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