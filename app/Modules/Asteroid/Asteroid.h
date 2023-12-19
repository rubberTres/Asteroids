//
// Created by Oskar Jaworski on 19/12/2023.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include <random>
#include "../Entity/Entity.h"

constexpr float ASTEROID_SPIN = 25.0f;
constexpr float ASTEROID_SPEED = 280.0f;
constexpr float ASTEROID_WIDTH = 90.0f;
constexpr float ASTEROID_HEIGHT = 80.0f;
constexpr float ASTEROID_SPAWN_TIME = 3.0f;

class Asteroid: public Entity {
public:
    Asteroid(sf::Vector2f direction = Asteroid::getRandomDirection(), sf::Vector2f position = Asteroid::getRandomPosition());

    void update(float deltaTime) override;

    void render(sf::RenderWindow& window) override;

    static sf::Vector2f getRandomDirection();

    static sf::Vector2f getRandomPosition();

private:
    sf::VertexArray array;
    sf::Vector2f direction;
};


#endif //ASTEROIDS_ASTEROID_H
