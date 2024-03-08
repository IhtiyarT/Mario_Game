cmake_minimum_required(VERSION 3.27)
project(Mario_Game)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/Users/DELL/source/C++libs/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6.1 REQUIRED graphics network audio window system)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(CMAKE_CXX_STANDARD 17)

add_executable(Mario_Game main.cpp
        Player/Player.h
        Player/Player.cpp
        main.h
        Enemy/Enemy.h
        Enemy/Enemy.cpp
        GameLogic/GameLogic.h
        GameLogic/GameLogic.cpp)

target_link_libraries(Mario_Game sfml-graphics sfml-window)