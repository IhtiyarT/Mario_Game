#include "Player.h"
using namespace sf;

Player::Player(sf::Texture &image) : Creature(image)
{
    _hit_box = FloatRect(100, 576, tile_size - 5, tile_size);
    _sprite.setTextureRect(IntRect(112, 144, texture_size, texture_size));

    _dx = _dy = _current_frame = 0;
    _on_ground = false;
}

void Player::update(float time, float& offsetX, float& offsetY){
    _hit_box.left += _dx * time;
    playerCollision(*this, 0);

    if(!_on_ground) _dy = _dy + 0.0005 * time;
    _hit_box.top += _dy * time;
    _on_ground = false;
    playerCollision(*this, 1);

    _current_frame += 0.005 * time;
    if(_current_frame > 3) _current_frame -= 3;

    if(_dx > 0) _sprite.setTextureRect(IntRect(112 + 31 * int(_current_frame), 144,
                                               texture_size, texture_size));
    if(_dx < 0) _sprite.setTextureRect(IntRect(112 + 31 * int(_current_frame) + texture_size,
                                               144, -texture_size, texture_size));
    if(_dx == 0) _sprite.setTextureRect(IntRect(82, 144,
                                                texture_size, texture_size));
    if(_dy != 0 && _dx < 0) _sprite.setTextureRect(IntRect(246, 144,
                                                   -texture_size, texture_size));
    if(_dy != 0 && _dx >= 0) _sprite.setTextureRect(IntRect(230, 144,
                                                   texture_size, texture_size));

    _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top - offsetY);

    _dx = 0;
}