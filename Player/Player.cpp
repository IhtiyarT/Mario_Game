#include "Player.h"
using namespace sf;

Player::Player(sf::Texture &image) : Creature(image)
{
    _hit_box = FloatRect(100, 570, tile_size-5, tile_size);
    _sprite.setTextureRect(IntRect(112, 144, texture_size, texture_size));
}

void Player::update(float time, float& offsetX){
    _hit_box.left += _dx * time;
    collision(0);

    if(!_on_ground) _dy += 0.002f * time;
    _hit_box.top += _dy;
    _on_ground = false;
    collision(1);

    animation(time);

    _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top);

}

void Player::collision(int dir) {
    for (size_t i = _hit_box.top / tile_size; i < (_hit_box.top + _hit_box.height) / tile_size; ++i){
        for (size_t j = _hit_box.left / tile_size; j < (_hit_box.left + _hit_box.width) / tile_size; ++j){
            if(i>=Height || j>=Width) break;
            int l = _hit_box.top/tile_size;
            if(TileMap[i][j] == 'B' || TileMap[i][j] == 'W' || TileMap[i][j] == 'T' || TileMap[i][j] == 't' || TileMap[i][j] == '0'){
                if(_dx > 0 && dir == 0) _hit_box.left = j * tile_size - _hit_box.width;
                if(_dx < 0 && dir == 0) _hit_box.left = j * tile_size + tile_size;
                if(_dy > 0 && dir == 1) {
                    _hit_box.top = i * tile_size - _hit_box.height;
                    _dy = 0;
                    _on_ground = true;
                }
                if(_dy < 0 && dir == 1) { _hit_box.top = i * tile_size + _hit_box.height; _dy = 0;}
            }
        }
    }
}


void Player::animation(float time){
    _current_frame += 0.005f * time;
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

void Player::playerMoves(float &offsetX){
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        if(_dx > -0.17) _dx -= 0.00035;
    }
    else if(_dx<0){
        _dx += 0.00035;
        if(_dx > 0) _dx = 0;
    }
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        if(_dx < 0.17) _dx += 0.00035;
    }
    else if(_dx>0){
        _dx -= 0.00035;
        if(_dx < 0) _dx = 0;
    }
    if(Keyboard::isKeyPressed(Keyboard::Up) && _on_ground){
        _dy -= 1.559;
        _on_ground = false;
    }

    if(_hit_box.left > sizeX / 2) offsetX = _hit_box.left - sizeX / 2;
}
