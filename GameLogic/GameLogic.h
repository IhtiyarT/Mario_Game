#ifndef MARIO_GAME_GAMELOGIC_H
#define MARIO_GAME_GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "../Blocks/Blocks.h"
#include <iostream>
#include <cstdio>  // FILENAME_MAX
#include "map.h"
#include <list>


inline float offsetX=34;
const double MS_PER_UPDATE = 16;

void windowRendering();
void mapRendering(sf::RenderWindow &win);
void getEnemies(std::list<Creature*> &list, const sf::Texture &texture);

#endif //MARIO_GAME_GAMELOGIC_H
