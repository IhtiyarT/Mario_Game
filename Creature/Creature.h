#ifndef MARIO_GAME_CREATURE_H
#define MARIO_GAME_CREATURE_H

#include <SFML/Graphics.hpp>
#include "map.h"


class Creature
{
protected:
    float _dx, _dy;
    sf::Sprite _sprite;
    float _current_frame;
    sf::FloatRect _hit_box;
    bool _on_ground, _is_alive;
    std::string _name;
public:
    explicit Creature(const sf::Texture &image);
    virtual ~Creature(){}
    void setDx(float dx){_dx = dx;}
    void setDy(float dy){_dy = dy;}
    sf::FloatRect getHitBox() const{return _hit_box;}
    sf::Sprite getSprite() const{return _sprite;}
    bool getLife()const {return _is_alive;}
    void setLife(bool life) {_is_alive = life;}
    std::string getName()const{return _name;}
    virtual void collision(int dir) = 0;
    virtual void update() = 0;
    virtual void animation() = 0;
};

#endif //MARIO_GAME_CREATURE_H
