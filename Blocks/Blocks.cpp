#include "Blocks.h"

Block::Block(const sf::Texture &texture, const std::string &name, float left, float top) : Creature(texture)
{
    _hit_box = sf::FloatRect(left, top, tile_size, tile_size);
    _name = name;
    if(_name == "Brick") _sprite.setTextureRect(sf::IntRect(143, 112,
                                                     texture_size, texture_size));
    else if(_name == "Lucky") _sprite.setTextureRect(sf::IntRect(127, 112, texture_size+1,
                                                          texture_size));
    _is_moving = false;
    _tick_counter = 0;
}

void Block::update(float &offsetX){
    if(_dy < 0 && _tick_counter < 5) { _hit_box.top -= 1; _is_moving = true; ++_tick_counter; _dy += 1; }
    else if(_is_moving && _tick_counter > 0) { _hit_box.top += 1; --_tick_counter;}
    else { _is_moving = false;}
    _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top);
}