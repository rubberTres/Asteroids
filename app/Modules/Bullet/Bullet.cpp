//
// Created by Oskar Jaworski on 19/12/2023.
//

#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction)
        : shape(1.0f), direction(direction), Entity(position, 0.0f), lifetime(BULLET_LIFE) {}

void Bullet::update(float deltaTime) {
    lifetime -= deltaTime;
    position += direction * BULLET_SPEED * deltaTime;
    if (lifetime <= 0.0f) {
        Game::toRemoveList.push_back(std::find(Game::entities.begin(), Game::entities.end(), this));
    }
}

void Bullet::render(sf::RenderWindow &window) {
    window.draw(shape, sf::Transform().translate(position));
}
