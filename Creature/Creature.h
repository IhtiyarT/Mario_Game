#ifndef MARIO_GAME_CREATURE_H
#define MARIO_GAME_CREATURE_H

#include <SFML/Graphics.hpp>

#define texture_size 16
#define tile_size 48

class Creature{
protected:
    float _dx, _dy;
    sf::Sprite _sprite;
    float _current_frame;
    sf::FloatRect _hit_box;
public:
    explicit Creature(sf::Texture &image);
    void setDx(float dx){_dx = dx;}
    void setDy(float dy){_dy = dy;}
    float getDx() const{return _dx;}
    float getDy() const{return _dy;}
    sf::FloatRect getHitBox() const{return _hit_box;}
    sf::Sprite getSprite() const{return _sprite;}
};

#endif //MARIO_GAME_CREATURE_H
