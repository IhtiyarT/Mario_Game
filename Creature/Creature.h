#ifndef MARIO_GAME_CREATURE_H
#define MARIO_GAME_CREATURE_H

#include <SFML/Graphics.hpp>
#include "../GameLogic/map.h"

#define texture_size 16
#define tile_size 48

class Creature{
protected:
    float _dx, _dy;
    sf::Sprite _sprite;
    float _current_frame;
    sf::FloatRect _hit_box;
    bool _on_ground;
public:
    explicit Creature(sf::Texture &image);
    void setDx(float dx){_dx = dx;}
    void setDy(float dy){_dy = dy;}
    float getDx() const{return _dx;}
    float getDy() const{return _dy;}
    sf::FloatRect getHitBox() const{return _hit_box;}
    sf::Sprite getSprite() const{return _sprite;}
    void setOnGround(bool on_ground){_on_ground = on_ground;}
    bool getOnGround() const{return _on_ground;}
    virtual void collision(int dir) = 0;
   // virtual void update(float time, float& offsetX, float& offsetY) = 0;
};

#endif //MARIO_GAME_CREATURE_H
