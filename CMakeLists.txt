cmake_minimum_required(VERSION 3.27)
project(Mario_Game)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.6.1 REQUIRED graphics network audio window system)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(CMAKE_CXX_STANDARD 17)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Mario_tileset.png
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Tileset.png
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/items_set.png
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/mario.png
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

include_directories(Creature
                    Blocks
                    Enemy
                    GameLogic
                    Observer
                    Player)

set(SOURCE_CPP main.cpp
        Player/Player.cpp
        Enemy/Enemy.cpp
        GameLogic/GameLogic.cpp
        Creature/Creature.cpp
        Observer/Observer.cpp
        Observer/Sounds.cpp
        Blocks/Blocks.cpp
        Observer/Effects.cpp
)

set(SOURCE_H main.h
        Enemy/Enemy.h
        GameLogic/GameLogic.h
        GameLogic/map.h
        Creature/Creature.h
        Observer/Observer.h
        Observer/Sounds.h
        Blocks/Blocks.h
        Observer/Effects.h
        Observer/SpriteContainer.h
        Creature/Mushroom.cpp
        Creature/Mushroom.h)

add_executable(Mario_Game ${SOURCE_CPP}
                            ${SOURCE_H})

target_link_libraries(Mario_Game sfml-graphics sfml-window sfml-audio)