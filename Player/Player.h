#ifndef MARIO_GAME_PLAYER_H
#define MARIO_GAME_PLAYER_H

#include "../Creature/Creature.h"

#define sizeX 1280
#define sizeY 704

class Player : public Creature
{
public:
    explicit Player(sf::Texture &image);
    void update(float time, float& offsetX, float& offsetY)override;
    void collision(int dir)override;
    void animation(float time)override;
};

#endif //MARIO_GAME_PLAYER_H
