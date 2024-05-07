#ifndef MARIO_GAME_PLAYER_H
#define MARIO_GAME_PLAYER_H

#include "Creature.h"
#include "Sounds.h"

#define sizeX 1280
#define sizeY 704

class Player : public Creature, public Subject
{
public:
    explicit Player(sf::Texture &image);
    ~Player()override{ removeObserver(&sounds);}
    void update(float& offsetX)override;
    void collision(int dir)override;
    void animation()override;
    void playerMoves(float &offsetX);
    void turnBack(){ _hit_box.top += _hit_box.height/5; _dy = 0;}
private:
    Sounds sounds;
};

#endif //MARIO_GAME_PLAYER_H
