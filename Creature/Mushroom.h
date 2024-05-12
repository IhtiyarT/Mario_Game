#ifndef MARIO_GAME_MUSHROOM_H
#define MARIO_GAME_MUSHROOM_H

#include "Creature.h"
#include "Observer.h"
#include "Sounds.h"

class Mushroom : public Creature, public Subject
{
public:
    explicit Mushroom(float left, float top);
    ~Mushroom();
    void update()override;
    void collision(int)override;
    void animation()override{};
private:
    double timer;
    sf::Texture mushroom_texture;
    Sounds _s_observer;
};


#endif //MARIO_GAME_MUSHROOM_H
