#ifndef MARIO_GAME_GAMELOGIC_H
#define MARIO_GAME_GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Blocks.h"
#include "Effects.h"
#include "map.h"
#include <list>
#include "Mushroom.h"
#include "../main.h"

inline float offsetX=34;

class Game{
public:
    Game();
    ~Game();
    bool windowRendering();
    void getEntities(std::list<Creature*> &list, const sf::Texture&, const sf::Texture&);
    void checkBlock(const Creature &creature);
    static void mapRendering(sf::RenderWindow &win, const sf::Texture&, const sf::Texture&);
private:
    sf::RenderWindow _win;
    sf::Music _music;
    Effects _effects;
    std::list<Creature*> _entities;
};

bool startGame();

#endif //MARIO_GAME_GAMELOGIC_H
