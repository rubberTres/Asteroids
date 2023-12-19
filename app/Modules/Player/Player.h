//
// Created by Oskar Jaworski on 19/12/2023.
//

#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H


#include "../Entity/Entity.h"
#include "../../Game/Game.h"
#include "../Bullet/Bullet.h"

constexpr float PLAYER_WIDTH = 50.0f;
constexpr float PLAYER_HEIGHT = 40.0f;
constexpr float TURN_SPEED = 200.0f;
constexpr float PLAYER_SPEED = 200.0f;
constexpr float SHOOT_DELAY = 0.2f;

class Player: public Entity {
public:
    Player();

    void render(sf::RenderWindow& window) override;

    void update(float deltaTime) override;


private:
    sf::VertexArray array;
    sf::Sound shootSound;

    float shootTimer;
};


#endif //ASTEROIDS_PLAYER_H
