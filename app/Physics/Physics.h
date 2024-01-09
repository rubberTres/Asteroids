//
// Created by Oskar Jaworski on 19/12/2023.
//

#ifndef ASTEROIDS_PHYSICS_H
#define ASTEROIDS_PHYSICS_H

#include <SFML/Graphics.hpp>

namespace physics {
    bool intersects(const sf::Vector2f& point, const sf::VertexArray& polygon);
    bool intersects(const sf::VertexArray &poly1, const sf::VertexArray &poly2);

    sf::VertexArray getTransformed(const sf::VertexArray& polygon, const sf::Transform& transform);

}

#endif //ASTEROIDS_PHYSICS_H
