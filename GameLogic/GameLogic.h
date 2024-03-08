#ifndef MARIO_GAME_GAMELOGIC_H
#define MARIO_GAME_GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include "../Player/Player.h"

#define texture_size 16
#define tile_size 32
#define Height 20
#define Width 80
#define sizeX 1280
#define sizeY 720


void windowRendering();
void playerMoves(Player&);

#endif //MARIO_GAME_GAMELOGIC_H
