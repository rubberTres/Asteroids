//
// Created by Oskar Jaworski on 19/12/2023.
//

#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H


#include "../Entity/Entity.h"
#include "../../Game/Game.h"
#include "../Bullet/Bullet.h"
#include "../Asteroid/Asteroid.h"

constexpr float PLAYER_WIDTH = 50.0f;
constexpr float PLAYER_HEIGHT = 40.0f;
constexpr float TURN_SPEED = 200.0f;
constexpr float PLAYER_SPEED = 200.0f;
constexpr float SHOOT_DELAY = 0.5f;

class Player: public Entity {
public:
    Player();

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    bool checkIntersects(Asteroid* asteroid);

private:
    sf::VertexArray array;

    float shootTimer;
};


#endif //ASTEROIDS_PLAYER_H
