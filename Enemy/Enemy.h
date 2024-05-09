#ifndef MARIO_GAME_ENEMY_H
#define MARIO_GAME_ENEMY_H

#include "Creature.h"
#include "Sounds.h"

class Enemy : public Creature, public Subject
{
public:
    explicit Enemy(const sf::Texture &image, const std::string &name, int left, int top, int width, int x, int y);
    ~Enemy()override;
    void update()override;
    void collision(int dir)override;
    void animation()override;
private:
    Sounds _s_observer;
protected:
};

#endif //MARIO_GAME_ENEMY_H
