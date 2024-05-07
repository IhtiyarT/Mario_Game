#ifndef MARIO_GAME_EFFECTS_H
#define MARIO_GAME_EFFECTS_H

#include "Observer.h"
#include <thread>

class Effects : public Observer
{
public:
    explicit Effects();
    ~Effects()override{}
    void onNotify(const Creature &creature, oEvent event)override;
private:
    sf::Sprite _sprite;
    sf::Vector2f _coordinates;
};


#endif //MARIO_GAME_EFFECTS_H
