#ifndef MARIO_GAME_CREATURE_H
#define MARIO_GAME_CREATURE_H

#include <SFML/Graphics.hpp>

#define texture_size 16
#define tile_size 32

class Creature{
protected:
    float _dx, _dy;
    sf::Sprite _sprite;
    float _current_frame;
    sf::FloatRect _hit_box;
public:
    explicit Creature(sf::Texture &image);
};

#endif //MARIO_GAME_CREATURE_H
