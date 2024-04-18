#ifndef MARIO_GAME_PLAYER_H
#define MARIO_GAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include "../Creature/Creature.h"

#define sizeX 1280
#define sizeY 720

class Player : public Creature
{
public:
    explicit Player(sf::Texture &image);
    void update(float time, float& offsetX, float& offsetY);
    void setOnGround(bool on_ground){_on_ground = on_ground;}
    bool getOnGround() const{return _on_ground;}
    friend void playerCollision(Player &p, int dir);
private:
    bool _on_ground;
};

#endif //MARIO_GAME_PLAYER_H
