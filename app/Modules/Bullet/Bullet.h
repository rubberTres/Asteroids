//
// Created by Oskar Jaworski on 19/12/2023.
//

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H


#include "../Entity/Entity.h"
#include "../../Game/Game.h"

constexpr float BULLET_SPEED = 400.0f;
constexpr float BULLET_LIFE = 3.0f;

class Bullet : public Entity {
public:
    Bullet(sf::Vector2f position, sf::Vector2f direction);

    void update(float deltaTime) override;

    void render(sf::RenderWindow& window) override;

private:
    sf::Vector2f direction;
    sf::CircleShape shape;
    float lifetime;
};


#endif //ASTEROIDS_BULLET_H
