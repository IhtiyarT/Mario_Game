cmake_minimum_required(VERSION 3.27)
project(Mario_Game)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_STANDARD 17)

add_executable(Mario_Game main.cpp)

target_link_libraries(Mario_Game sfml-graphics)

set(SFML_DIR "C:/Users/DELL/source/C++libs/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6.1 REQUIRED graphics network audio window system)