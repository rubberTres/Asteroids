//
// Created by Oskar Jaworski on 19/12/2023.
//

#ifndef ASTEROIDS_ENTITY_H
#define ASTEROIDS_ENTITY_H

#include <SFML/Graphics.hpp>

constexpr float SCREEN_WIDTH = 1200.0f;
constexpr float SCREEN_HEIGHT = 900.0f;

class Entity {
public:
    Entity(sf::Vector2f position, float angle)
            : position(position), angle(angle) {};

    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

    sf::Vector2f position;
    float angle;
};


#endif //ASTEROIDS_ENTITY_H
