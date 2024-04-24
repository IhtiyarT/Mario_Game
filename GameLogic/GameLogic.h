#ifndef MARIO_GAME_GAMELOGIC_H
#define MARIO_GAME_GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include <iostream>
#include <cstdio>  // FILENAME_MAX

#ifdef WIN32
#include <direct.h>
#define GetCurrentDir _getcwd

#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

void windowRendering();
void playerMoves(Player&);
void mapRendering(sf::RenderWindow &win, const char *cCurrentPath);

#endif //MARIO_GAME_GAMELOGIC_H
