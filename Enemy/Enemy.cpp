#include "Enemy.h"

using namespace sf;

Enemy::Enemy(Texture &image) : Creature(image)
{
    _hit_box = FloatRect(100, 576, tile_size-5, tile_size);
    _sprite.setTextureRect(IntRect(0, 0, texture_size, texture_size));
    _is_alive = true;
    _dx = 0.07;
}

void Enemy::update(float time, float& offsetX, float& offsetY){
    _hit_box.left += _dx*time;
    collision(0);

    if(!_on_ground) _dy = _dy + 0.0005 * time;
    _hit_box.top += _dy*time/2;
    _on_ground = false;
    collision(1);

    _current_frame += time*0.005;
    if(_current_frame>2) _current_frame -= 2;

    _sprite.setTextureRect(IntRect(19*int(_current_frame), 0, texture_size, texture_size));
    _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top - offsetY);

}

void Enemy::collision(int dir) {
    for (int i = _hit_box.top / tile_size; i < (_hit_box.top + _hit_box.height) / tile_size; ++i){
        for (int j= _hit_box.left / tile_size; j < (_hit_box.left + _hit_box.width) / tile_size; ++j){
            if(TileMap[i][j] == 'B' || TileMap[i][j] == 'W'){
                if(_dx > 0 && dir == 0) {_hit_box.left = j * tile_size - _hit_box.width;_dx *= -1; }
                else if(_dx < 0 && dir == 0) {_hit_box.left = j * tile_size + tile_size; _dx *= -1; }
                if(_dy > 0 && dir == 1){
                    _hit_box.top = i * tile_size - _hit_box.height;
                    _dy = 0;
                    _on_ground = true;
                }
                if (_dy < 0 && dir == 1) { _hit_box.top = i * tile_size + tile_size; _dy = 0;}
            }
        }
    }
}

