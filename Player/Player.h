#ifndef MARIO_GAME_PLAYER_H
#define MARIO_GAME_PLAYER_H

#include "Creature.h"
#include "../Observer/Sounds.h"

#define sizeX 1280
#define sizeY 704

class Player : public Creature, public Subject
{
public:
    explicit Player(sf::Texture &image);
    void update(float time, float& offsetX)override;
    void collision(int dir)override;
    void animation(float time)override;
    void playerMoves(float &offsetX);
private:
    Sounds sounds;
};

#endif //MARIO_GAME_PLAYER_H
