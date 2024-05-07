#ifndef MARIO_GAME_BLOCKS_H
#define MARIO_GAME_BLOCKS_H

#include "Creature.h"
#include <string>

class Block : public Creature
{
public:
    Block(const sf::Texture &texture, float left, float top);
protected:
    int _tick_counter;
};

class LuckyBlock : public Block
{
public:
    LuckyBlock(const sf::Texture &texture, float left, float top);
    void update(float &offsetX)override;
    void animation()override;
    void collision(int)override;
private:
    bool _is_coin;
};

class BrickBlock : public Block
{
public:
    BrickBlock(const sf::Texture &texture, float left, float top);
    void update(float &offsetX)override;
    void collision(int)override;
    void animation()override{}
};


#endif //MARIO_GAME_BLOCKS_H
