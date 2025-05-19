//#include <SFML/Graphics.hpp>
//#include "Window/window.h"
//
//int main()
//{
//	
//	Window window;
//	window.windowLoop();
//
//	return 0;
//
// }
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

class InputField {
public:
    sf::RectangleShape box;
    sf::Text text;
    std::string content;
    bool isFocused = false;
    bool isPassword = false;

    sf::RectangleShape cursor;
    sf::Clock blinkClock;
    bool cursorVisible = true;

    InputField(float x, float y, float width, float height, sf::Font& font, bool password = false) {
        isPassword = password;
        box.setPosition(x, y);
        box.setSize(sf::Vector2f(width, height));
        box.setFillColor(sf::Color(230, 230, 230));
        box.setOutlineColor(sf::Color::Black);
        box.setOutlineThickness(2);

        text.setFont(font);
        text.setCharacterSize(22);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + 10, y + 10);

        cursor.setSize(sf::Vector2f(2, 26));
        cursor.setFillColor(sf::Color::Black);
        cursor.setPosition(x + 10, y + 10);
    }

    void handleEvent(sf::Event& event) {
        if (!isFocused) return;

        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128) {
                char c = static_cast<char>(event.text.unicode);
                if (c == 8 && !content.empty()) { // Backspace
                    content.pop_back();
                }
                else if (isprint(c)) {
                    content += c;
                }
                updateTextDisplay();
                updateCursorPos();
            }
        }
    }

    void updateTextDisplay() {
        if (isPassword) {
            std::string hidden(content.size(), '*');
            text.setString(hidden);
        }
        else {
            text.setString(content);
        }
    }

    void updateCursorPos() {
        float xOffset = text.getLocalBounds().width;
        cursor.setPosition(box.getPosition().x + 10 + xOffset, box.getPosition().y + 10);
    }

    void updateBlink() {
        if (!isFocused) return;
        if (blinkClock.getElapsedTime().asSeconds() >= 0.5f) {
            cursorVisible = !cursorVisible;
            blinkClock.restart();
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(box);
        window.draw(text);
        if (isFocused && cursorVisible)
            window.draw(cursor);
    }

    bool isMouseOver(sf::Vector2f mousePos) {
        return box.getGlobalBounds().contains(mousePos);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Login Form");
    sf::Font font;
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cout << "Font not found!" << std::endl;
        return 1;
    }

    // Input fields
    InputField username(300, 200, 300, 50, font);
    InputField password(300, 300, 300, 50, font, true);
    std::vector<InputField*> fields = { &username, &password };

    // Labels
    sf::Text usernameLabel, passwordLabel;
    usernameLabel.setFont(font);
    usernameLabel.setCharacterSize(22);
    usernameLabel.setFillColor(sf::Color::Black);
    usernameLabel.setString("Username:");
    usernameLabel.setPosition(200, 210);

    passwordLabel.setFont(font);
    passwordLabel.setCharacterSize(22);
    passwordLabel.setFillColor(sf::Color::Black);
    passwordLabel.setString("Password:");
    passwordLabel.setPosition(200, 310);

    // Submit Button
    sf::RectangleShape submitBtn(sf::Vector2f(150, 50));
    submitBtn.setFillColor(sf::Color(100, 180, 255));
    submitBtn.setPosition(325, 400);

    sf::Text submitText;
    submitText.setFont(font);
    submitText.setCharacterSize(22);
    submitText.setFillColor(sf::Color::White);
    submitText.setString("Submit");
    submitText.setPosition(355, 410);

    bool submitted = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window
            if (event.type == sf::Event::Closed)
                window.close();

            // Mouse click handling
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                for (auto& field : fields)
                    field->isFocused = field->isMouseOver(mousePos);

                // Submit button clicked
                if (submitBtn.getGlobalBounds().contains(mousePos)) {
                    submitted = true;
                    std::cout << "Username: " << username.content << "\n";
                    std::cout << "Password: " << password.content << "\n";
                }
            }

            // Typing
            for (auto& field : fields) {
                field->handleEvent(event);
            }
        }

        for (auto& field : fields)
            field->updateBlink();

        window.clear(sf::Color::White);
        window.draw(usernameLabel);
        window.draw(passwordLabel);
        for (auto& field : fields)
            field->draw(window);
        window.draw(submitBtn);
        window.draw(submitText);
        window.display();
    }

    return 0;
}
