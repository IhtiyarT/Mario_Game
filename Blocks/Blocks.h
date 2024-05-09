#ifndef MARIO_GAME_BLOCKS_H
#define MARIO_GAME_BLOCKS_H

#include "Creature.h"
#include "Effects.h"
#include "Sounds.h"
#include <string>

class Block : public Creature, public Subject
{
public:
    Block(const sf::Texture &texture, float left, float top, Effects &effects);
    ~Block()override{}
    void update()override = 0;
    void animation()override = 0;
    void collision(int)override = 0;
protected:
    int _tick_counter;
    Sounds _s_observer;
};

class LuckyBlock : public Block
{
public:
    LuckyBlock(const sf::Texture &texture, float left, float top, Effects &effects);
    void update()override;
    void animation()override;
    void collision(int)override;
private:
    bool _is_coin;
    sf::Sprite _coin_sprite;
};

class BrickBlock : public Block
{
public:
    BrickBlock(const sf::Texture &texture, float left, float top, Effects &effects);
    void update()override;
    void collision(int)override;
    void animation()override{}
};


#endif //MARIO_GAME_BLOCKS_H
