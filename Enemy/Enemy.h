#ifndef MARIO_GAME_ENEMY_H
#define MARIO_GAME_ENEMY_H

#include "../Creature/Creature.h"

class Enemy : public Creature
{
public:
    explicit Enemy(sf::Texture &image);
    void update(float time, float& offsetX, float& offsetY)override;
    void collision(int dir)override;
    void animation(float time)override;
    bool getLife()const {return _is_alive;}
    void setLife(bool life=false) {_is_alive = life;}
protected:
    bool _is_alive;
};

#endif //MARIO_GAME_ENEMY_H
