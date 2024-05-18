#include "Mushroom.h"
#include "GameLogic.h"

Mushroom::Mushroom(float left, float top)
{
    sf::Image img;
    img.loadFromFile("items_set.png");
    img.createMaskFromColor(sf::Color(146, 144, 255));

    mushroom_texture.loadFromImage(img);

    _sprite.setTexture(mushroom_texture);
    _sprite.setScale(sf::Vector2f(2, 2));
    _hit_box = sf::FloatRect(left, top-2, tile_size, tile_size-1);
    _sprite.setTextureRect(sf::IntRect(0, 9, texture_size, texture_size-1));

    _is_alive = true;
    _name = "Bonus";
    _dx = 2;

    addObserver(&_s_observer);

    timer = 0;
}

Mushroom::~Mushroom(){
    removeObserver(&_s_observer);
}

void Mushroom::update(){
    timer += 0.1;
    if(int(timer) <= 7){
        _hit_box.top -= 0.4f;
        _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top);
    }
    else{
        _hit_box.left += _dx;
        collision(0);

        if (!_on_ground) _dy += 0.1;
        _hit_box.top += _dy;
        _on_ground = false;
        collision(1);

        _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top);
    }
}

void Mushroom::collision(int dir){
    if(dir == 3){
        _is_alive = false;
        notify(*this, oEvent::MUSHROOM_ATE);
        return;
    }
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
