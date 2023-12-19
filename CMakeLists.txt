cmake_minimum_required(VERSION 3.14)
project(Asteroids)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        app/Modules/Asteroid/Asteroid.cpp
        app/Modules/Asteroid/Asteroid.h
        app/Modules/Entity/Entity.cpp
        app/Modules/Entity/Entity.h
        app/Modules/Bullet/Bullet.cpp
        app/Modules/Bullet/Bullet.h
        app/Modules/Player/Player.cpp
        app/Modules/Player/Player.h
        app/Game/Game.cpp
        app/Game/Game.h)
add_executable(HelloSFML ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)