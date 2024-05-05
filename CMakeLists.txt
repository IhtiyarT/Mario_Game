cmake_minimum_required(VERSION 3.27)
project(Mario_Game)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/Users/DELL/source/C++libs/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6.1 REQUIRED graphics network audio window system)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(CMAKE_CXX_STANDARD 17)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Mario_tileset.png
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Tileset.png
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/sound/jump.wav
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

include_directories(assets/sound Creature)

add_executable(Mario_Game main.cpp
        Player/Player.h
        Player/Player.cpp
        main.h
        Enemy/Enemy.h
        Enemy/Enemy.cpp
        GameLogic/GameLogic.h
        GameLogic/GameLogic.cpp
        GameLogic/map.h
        Creature/Creature.cpp
        Creature/Creature.h
        Observer/Observer.cpp
        Observer/Observer.h
        Observer/Sounds.cpp
        Observer/Sounds.h
        Blocks/Blocks.cpp
        Blocks/Blocks.h)

target_link_libraries(Mario_Game sfml-graphics sfml-window sfml-audio)