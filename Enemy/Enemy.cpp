#include "Enemy.h"
#include "GameLogic.h"

using namespace sf;

Enemy::Enemy(const Texture &image, const std::string &name, int left, int top, int width, int x, int y) : Creature(image)
{
    _hit_box = FloatRect(left, top, width, tile_size);
    _sprite.setTextureRect(IntRect(x, y, texture_size, texture_size));
    _is_alive = true;
    _name = name;
    _dx = 1;
    addObserver(&sound);
}

void Enemy::update(){
    _hit_box.left += _dx;
    collision(0);

    if(!_on_ground) _dy += 0.08;
    _hit_box.top += _dy;
    _on_ground = false;
    collision(1);

    animation();

    _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top);
}

void Enemy::animation(){
    _current_frame += 0.05;
    if(_current_frame>2) _current_frame -= 2;
    if(!_is_alive) { _current_frame = 3; notify(*this, oEvent::MUSHROOM_DIED);}

    _sprite.setTextureRect(IntRect(19*int(_current_frame), 0,
                                   texture_size, texture_size));
}

void Enemy::collision(int dir){
    for (size_t i = _hit_box.top / tile_size; i < (_hit_box.top + _hit_box.height) / tile_size; ++i){
        if(i>=Height) continue;
        for (size_t j= _hit_box.left / tile_size; j < (_hit_box.left + _hit_box.width) / tile_size; ++j){
            if(TileMap[i][j] == 'B' || TileMap[i][j] == 'W' || TileMap[i][j] == 'T' || TileMap[i][j] == 't'
               || TileMap[i][j] == '0' || TileMap[i][j] == 's' || TileMap[i][j] == 'b'){
                if (_dx > 0 && dir == 0) {
                    _hit_box.left = j * tile_size - _hit_box.width;
                    _dx *= -1;
                }
                else if (_dx < 0 && dir == 0) {
                    _hit_box.left = j * tile_size + tile_size;
                    _dx *= -1;
                }
                if (_dy > 0 && dir == 1) {
                    _hit_box.top = i * tile_size - _hit_box.height;
                    _dy = 0;
                    _on_ground = true;
                }
            }
        }
    }
}

