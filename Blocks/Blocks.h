#ifndef MARIO_GAME_BLOCKS_H
#define MARIO_GAME_BLOCKS_H

#include "../Creature/Creature.h"
#include <string>

class Block : public Creature
{
public:
    Block(const sf::Texture &texture, const std::string &name, float left, float top);
    void update(float &offsetX)override;
    void collision(int dir)override{}
    void animation()override;
private:
    int _tick_counter;
    float _top, _left;
};


#endif //MARIO_GAME_BLOCKS_H
