#ifndef MARIO_GAME_PLAYER_H
#define MARIO_GAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include "../Creature/Creature.h"

#define texture_size 16
#define tile_size 32
#define sizeX 1280
#define sizeY 720

class Player : public Creature
{
public:
    explicit Player(sf::Texture &image);
    void update(float time, float& offsetX, float& offsetY);
    void setDx(float dx){_dx = dx;}
    void setDy(float dy){_dy = dy;}
    void setOnGround(bool on_ground){_on_ground = on_ground;}
    float getDx() const{return _dx;}
    float getDy() const{return _dy;}
    bool getOnGround() const{return _on_ground;}
    sf::FloatRect getHitBox() const{return _hit_box;}
    sf::Sprite getSprite() const{return _sprite;}
    friend void playerCollision(Player &p, int dir);
private:
    bool _on_ground;
};

#endif //MARIO_GAME_PLAYER_H
