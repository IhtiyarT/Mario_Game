#include "Player.h"
#include "GameLogic.h"
using namespace sf;

Player::Player(sf::Texture &image, Effects &effect) : Creature(image)
{
    _hit_box = FloatRect(100, 570, tile_size-5, tile_size);
    _sprite.setTextureRect(IntRect(209, 0, texture_size, texture_size));
    addObserver(&_s_observer);
    addObserver(&effect);
    _is_big = false;
}

Player::~Player(){
    removeObserver(&_s_observer);
}

void Player::update(){
    if(!_is_alive) return;
    _hit_box.left += _dx;
    collision(0);

    if(!_on_ground) _dy += 0.15;
    _hit_box.top += _dy;
    _on_ground = false;
    collision(1);

    playerMoves();
    animation();

    _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top);
    if(this->_hit_box.top > 750) this->setLife(false);
}

void Player::collision(int dir) {
    for (size_t i = _hit_box.top / tile_size; i < (_hit_box.top + _hit_box.height) / tile_size; ++i){
        for (size_t j = _hit_box.left / tile_size; j < (_hit_box.left + _hit_box.width) / tile_size; ++j){
            if(i>=Height || j>=Width) break;
            if(TileMap[i][j] == 'B' || TileMap[i][j] == 'W' || TileMap[i][j] == 'T' || TileMap[i][j] == 't'
                       || TileMap[i][j] == '0' || TileMap[i][j] == 's' || TileMap[i][j] == 'b' || TileMap[i][j] == 'm'){
                if(_dx > 0 && dir == 0) { _hit_box.left = j * tile_size - _hit_box.width; if(_dx > 0.005) _dx -= 0.005;}
                if(_dx < 0 && dir == 0) { _hit_box.left = j * tile_size + tile_size; if(_dx < -0.005) _dx += 0.005;}
                if(_dy > 0 && dir == 1) {
                    _hit_box.top = i * tile_size - _hit_box.height;
                    _dy = 0;
                    _on_ground = true;
                }
            }
        }
    }
}

void Player::setBig(bool big){
    _is_big = big;
    _dy = -1;
    _hit_box = FloatRect(_hit_box.left, _hit_box.top-tile_size, tile_size, tile_size*2);
    _sprite.setPosition(_hit_box.left, _hit_box.top);
}


void Player::animation(){
    _current_frame += 0.08;
    int size_coef = _is_big;
    if(_current_frame > 3) _current_frame -= 3;
    using Kb = Keyboard;

    if(_dx > 0 && (Kb::isKeyPressed(Kb::Left) || Kb::isKeyPressed(Kb::A))) _sprite.setTextureRect(
       IntRect(329,26 * size_coef * 2,texture_size, texture_size*(1 + size_coef)));
    else if(_dx > 0) _sprite.setTextureRect(IntRect(301 - 31 * int(_current_frame),
                         26 * size_coef * 2,texture_size, texture_size*(1 + size_coef)));
    if(_dx < 0 && (Kb::isKeyPressed(Kb::Right) || Kb::F)) _sprite.setTextureRect(IntRect(345,
                         26 * size_coef * 2,-texture_size, texture_size*(1 + size_coef)));
    else if(_dx < 0) _sprite.setTextureRect(IntRect(301 - 31 * int(_current_frame) + texture_size,
                         26 * size_coef * 2, -texture_size, texture_size*(1 + size_coef)));
    if(_dx == 0) _sprite.setTextureRect(IntRect(209, 26 * size_coef * 2,
                         texture_size, texture_size*(1 + size_coef)));
    if(_dy != 0 && _dx < 0) _sprite.setTextureRect(IntRect(375, 26 * size_coef * 2,
                         -texture_size-3, texture_size*(1 + size_coef)));
    if(_dy != 0 && _dx >= 0) _sprite.setTextureRect(IntRect(357, 26 * size_coef * 2,
                          texture_size+3, texture_size*(1 + size_coef)));
}

void Player::playerMoves(){
    using Kb = Keyboard;
    if(_hit_box.left <= offsetX) { _hit_box.left = offsetX; _dx = 0; }
    else if(Kb::isKeyPressed(Kb::Left) || Kb::isKeyPressed(Kb::Key::A)){
        if(_dx > -3.5) _dx -= 0.05;
    }
    else if(_dx<0){
        _dx += 0.03;
        if(_dx > 0) _dx = 0;
    }
    if(Kb::isKeyPressed(Kb::Right) || Kb::isKeyPressed(Kb::Key::D)){
        if(_dx < 3.5) _dx += 0.05;
    }
    else if(_dx>0){
        _dx -= 0.03;
        if(_dx < 0) _dx = 0;
    }
    if((Kb::isKeyPressed(Keyboard::Up) || Kb::isKeyPressed(Kb::W)) && _on_ground){
        _dy -= 7.1;
        _on_ground = false;
        notify(*this, oEvent::PLAYER_JUMP);
    }
    if(_hit_box.left > sizeX / 2 && offsetX < _hit_box.left - sizeX/2) offsetX = _hit_box.left - sizeX / 2;
}

void Player::enemyIntersect(){
    if(_is_big) {
        _is_big = false;
        _hit_box = FloatRect(_hit_box.left, _hit_box.top, tile_size-5, tile_size);
    }
    else if(getLife()) setLife(false);
}
