//
// Created by Oskar Jaworski on 19/12/2023.
//

#include "Game.h"
#include "../Modules/Player/Player.h"
#include "../Modules/Asteroid/Asteroid.h"

std::vector<Entity*> Game::entities{};
std::list<std::vector<Entity*>::const_iterator> Game::toRemoveList{};
std::list<Entity*> Game::toAddList{};
float Game::asteroidSpawnTime{};

void Game::begin() {
    entities.push_back(new Player());
    asteroidSpawnTime = ASTEROID_SPAWN_TIME;
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
}