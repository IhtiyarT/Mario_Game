#include "Blocks.h"

Block::Block(const sf::Texture &texture, const std::string &name, float left, float top) : Creature(texture)
{
    _left = left;
    _top = top;
    _hit_box = sf::FloatRect(left, top, tile_size, tile_size);
    _name = name;
    if(_name == "Brick") _sprite.setTextureRect(sf::IntRect(144, 112,
                                                     texture_size, texture_size));
    else if(_name == "Lucky") _sprite.setTextureRect(sf::IntRect(298, 78, texture_size,
                                                          texture_size));
    _tick_counter = 0;
}

void Block::update(float &offsetX){
    if(_name == "Lucky") animation();
    if(_dy < 0) { _top -= 1; ++_tick_counter; _dy += 1; }
    else if(_tick_counter != 0) { _top += 1; --_tick_counter;}
    _sprite.setPosition(_left - offsetX, _top);
}

void Block::animation() {
    _current_frame += 0.08;
    if(_current_frame > 3) _current_frame -= 3;

    if(_is_alive) _sprite.setTextureRect(sf::IntRect(298 + (int)_current_frame * (texture_size+1), 78,
                                       texture_size,texture_size));
    else _sprite.setTextureRect(sf::IntRect(349, 78, texture_size,
                                            texture_size));
}
