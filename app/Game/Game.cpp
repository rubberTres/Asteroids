//
// Created by Oskar Jaworski on 19/12/2023.
//

#include "Game.h"
#include "../Modules/Player/Player.h"
#include "../Modules/Asteroid/Asteroid.h"

std::vector<Entity*> Game::entities{};
std::list<std::vector<Entity*>::const_iterator> Game::toRemoveList{};
std::list<Entity*> Game::toAddList{};

std::unordered_map<std::string, sf::SoundBuffer> Game::soundBuffers;
size_t Game::score{};
float Game::asteroidSpawnTime{};

sf::Text Game::scoreText{};
sf::Font Game::font{};

void Game::begin() {
    font.loadFromFile("../font.ttf");
    scoreText.setFont(font);
    scoreText.setPosition(sf::Vector2f(48, 20));
    scoreText.setCharacterSize(40);

    entities.push_back(new Player());
    asteroidSpawnTime = ASTEROID_SPAWN_TIME;

    soundBuffers["shoot"].loadFromFile("../app/sounds/shoot.mp3");
}

void Game::update(sf::RenderWindow &window, float deltaTime) {
    toAddList.clear();
    toRemoveList.clear();
    window.clear();

    asteroidSpawnTime -= deltaTime;

    for (size_t i = 0; i < entities.size(); i++) {
        entities[i]->update(deltaTime);
        entities[i]->render(window);
    }

    for (const auto& item : toRemoveList) {
        delete* item;
        entities.erase(item);
    }

    for (auto& ptr : toAddList) {
        entities.push_back(ptr);
    }

    if (asteroidSpawnTime <= 0.0f) {
        entities.push_back(new Asteroid());
        asteroidSpawnTime = ASTEROID_SPAWN_TIME;
    }

    scoreText.setString(std::to_string(score));
    window.draw(scoreText);
}