#include <iostream>
#include "app/Game/Game.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Asteroids game AGH", sf::Style::Close | sf::Style::Titlebar);
    sf::Clock clock;

    Game::init();
    Game::begin();

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        sf::Event e{};
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }

        Game::update(window, deltaTime);

        window.display();
    }
}

