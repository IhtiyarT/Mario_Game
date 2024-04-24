#ifndef MARIO_GAME_ENEMY_H
#define MARIO_GAME_ENEMY_H

#include "../Creature/Creature.h"

class Enemy : public Creature
{
public:
    explicit Enemy(sf::Texture &image);
    void update(float time, float& offsetX, float& offsetY);
    void collision(int dir)override;
protected:
    bool _is_alive;
};

#endif //MARIO_GAME_ENEMY_H
