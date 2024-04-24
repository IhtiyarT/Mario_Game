#include "Player.h"
using namespace sf;

Player::Player(sf::Texture &image) : Creature(image)
{
    _hit_box = FloatRect(100, 576, tile_size-5, tile_size);
    _sprite.setTextureRect(IntRect(112, 144, texture_size, texture_size));
}

void Player::update(float time, float& offsetX, float& offsetY){
    _hit_box.left += _dx * time;
    collision(0);

    if(!_on_ground) _dy = _dy + 0.0005 * time;
    _hit_box.top += _dy * time;
    _on_ground = false;
    collision(1);

    animation(time);

    _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top - offsetY);

    _dx = 0;
}

void Player::collision(int dir) {
    for (int i = _hit_box.top / tile_size; i < (_hit_box.top + _hit_box.height) / tile_size; ++i){
        if(i>Height) break;
        for (int j= _hit_box.left / tile_size; j < (_hit_box.left + _hit_box.width) / tile_size; ++j){
            if(TileMap[i][j] == 'B' || TileMap[i][j] == 'W'){
                if(_dx > 0 && dir == 0) _hit_box.left = j * tile_size - _hit_box.width;
                if(_dx < 0 && dir == 0) _hit_box.left = j * tile_size + tile_size;
                if(_dy > 0 && dir == 1){
                    _hit_box.top = i * tile_size - _hit_box.height;
                    _dy = 0;
                    _on_ground = true;
                }
                if (_dy < 0 && dir == 1) { _hit_box.top = i * tile_size + tile_size; _dy = 0;}
            }
            if(TileMap[i][j]=='0'){
                TileMap[i][j] = ' ';
            }
        }
    }
}

void Player::animation(float time){
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
}
