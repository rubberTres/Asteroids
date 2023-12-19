//
// Created by Oskar Jaworski on 19/12/2023.
//

#include "Bullet.h"
#include "../Asteroid/Asteroid.h";

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction)
        : shape(1.0f), direction(direction), Entity(position, 0.0f), lifetime(BULLET_LIFE) {}

void Bullet::update(float deltaTime) {
    lifetime -= deltaTime;
    position += direction * BULLET_SPEED * deltaTime;
    if (lifetime <= 0.0f) {
        Game::toRemoveList.push_back(std::find(Game::entities.begin(), Game::entities.end(), this));
    }

    for (size_t i = 0; i < Game::entities.size(); i++) {
        if (typeid(*Game::entities[i]) == typeid(Asteroid)) {
            Asteroid* asteroid = dynamic_cast<Asteroid*>(Game::entities[i]);
            const sf::VertexArray& polygon = asteroid->getVertexArray();
            sf::Transform transform = sf::Transform()
                    .translate(asteroid->position)
                    .rotate(asteroid->angle);

            size_t n = polygon.getVertexCount() - 1;
            size_t intersectionCount = 0;
            sf::Vector2f  rayEnd = sf::Vector2f(std::numeric_limits<float>::max(), position.y);

            for (size_t j = 0; j < n; j++) {
                sf::Vector2f p1 = transform.transformPoint(polygon[j].position);
                sf::Vector2f p2 = transform.transformPoint(polygon[(j + 1) % n].position);

                if ((p1.y < position.y && p2.y >= position.y) || (p2.y < position.y && p1.y >= position.y)) {
                    float t = (position.y - p1.y) / (p2.y - p1.y);
                    float intersectX = p1.x + t * (p2.x - p1.x);

                    if (intersectX <= position.x && intersectX <= rayEnd.x) {
                        intersectionCount++;
                    }
                }
            }

            if (intersectionCount % 2 == 1) {
                lifetime = 0.0f;
            }
        }
    }
}

void Bullet::render(sf::RenderWindow &window) {
    window.draw(shape, sf::Transform().translate(position));
}
