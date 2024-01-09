//
// Created by Oskar Jaworski on 19/12/2023.
//

#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H


#include <unordered_map>
#include <vector>
#include <list>
#include <SFML/Audio/SoundBuffer.hpp>
#include "../Modules/Entity/Entity.h"
#include <SFML/Audio.hpp>

class Game {

public:
    static void init();
    static void begin();
    static void update(sf::RenderWindow& window, float deltaTime);

    static void gameOver();

    static std::vector<Entity*> entities;
    static std::list<std::vector<Entity*>::const_iterator> toRemoveList;
    static std::list<Entity*> toAddList;

    static size_t score;

    static sf::SoundBuffer shootSoundBuffer;
    static sf::Sound shootSound;

private:
    static float asteroidSpawnTime;
    static sf::Text scoreText;
    static sf::Font font;

    static bool isGameOver;
};


#endif //ASTEROIDS_GAME_H
