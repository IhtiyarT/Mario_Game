#ifndef MARIO_GAME_GAMELOGIC_H
#define MARIO_GAME_GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Blocks.h"
#include <iostream>
#include "map.h"
#include <list>

inline float offsetX=34;

class Game{
public:
    Game();
    void windowRendering();
    static void mapRendering(sf::RenderWindow &win, const sf::Texture&, const sf::Texture&);
private:
    sf::RenderWindow _win;
    sf::Music music;
};

void getEntities(std::list<Creature*> &list, const sf::Texture&, const sf::Texture&);

#endif //MARIO_GAME_GAMELOGIC_H
