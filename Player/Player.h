#ifndef MARIO_GAME_PLAYER_H
#define MARIO_GAME_PLAYER_H

#include "Creature.h"
#include "Sounds.h"
#include "Effects.h"

#define sizeX 1280
#define sizeY 704

class Player : public Creature, public Subject
{
public:
    explicit Player(sf::Texture &image, Effects &effects);
    ~Player()override;
    void setLife(bool life)override{_is_alive = life; notify(*this, oEvent::PLAYER_DIED);}
    void setBig(bool big);
    void update()override;
    void collision(int dir)override;
    void animation()override;
    void playerMoves();
    void turnBack(){ _hit_box.top += _hit_box.height/5; _dy = 0;}
    void enemyIntersect();
private:
    bool _is_big;
    Sounds _s_observer;
};

#endif //MARIO_GAME_PLAYER_H
