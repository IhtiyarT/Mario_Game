#ifndef MARIO_GAME_ENEMY_H
#define MARIO_GAME_ENEMY_H

#include "Creature.h"
#include "Sounds.h"

class Enemy : public Creature, public Subject
{
public:
    explicit Enemy(const sf::Texture &image, const std::string &name, int left, int top, int width, int x, int y);
    ~Enemy(){ removeObserver(&sound);}
    void update(float& offsetX)override;
    void collision(int dir)override;
    void animation()override;
protected:
    Sounds sound;
};

#endif //MARIO_GAME_ENEMY_H
