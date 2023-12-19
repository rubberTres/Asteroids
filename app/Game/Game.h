//
// Created by Oskar Jaworski on 19/12/2023.
//

#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H


#include <vector>
#include <list>
#include "../Modules/Entity/Entity.h"

class Game {

public:
    static void begin();
    static void update(sf::RenderWindow& window, float deltaTime);

    static std::vector<Entity*> entities;
    static std::list<std::vector<Entity*>::const_iterator> toRemoveList;
    static std::list<Entity*> toAddList;

private:
    static float asteroidSpawnTime;
};


#endif //ASTEROIDS_GAME_H
