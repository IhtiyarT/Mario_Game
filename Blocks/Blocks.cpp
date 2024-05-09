#include "Blocks.h"
#include "GameLogic.h"

Block::Block(const sf::Texture &texture, float left, float top, Effects &effects) : Creature(texture)
{
    _hit_box = sf::FloatRect(left, top, tile_size, tile_size);
    _tick_counter = 0;
    _name = "Block";
    addObserver(&effects);
    addObserver(&_s_observer);
}

BrickBlock::BrickBlock(const sf::Texture &texture, float left, float top, Effects &effects) : Block(texture, left, top, effects) {
    _sprite.setTextureRect(sf::IntRect(144, 112,
                                       texture_size, texture_size));
}

void BrickBlock::update(){
    if(_dy < 0) { _hit_box.top -= 1; ++_tick_counter; _dy += 1; }
    else if(_tick_counter != 0) { _hit_box.top += 1; --_tick_counter;}
    _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top);
}

void BrickBlock::collision(int) {
    _dy = -6;
}


LuckyBlock::LuckyBlock(const sf::Texture &texture, float left, float top, Effects &effects) : Block(texture, left, top, effects)
{
    _sprite.setTextureRect(sf::IntRect(298, 78, texture_size,
                                       texture_size));
    _is_coin = true;

    sf::Image items_img;
    items_img.loadFromFile("items_set.png");
    items_img.createMaskFromColor(sf::Color(146, 144, 255));
    sf::Texture _set_of_items;
    _set_of_items.loadFromImage(items_img);

    _coin_sprite.setTexture(_set_of_items);
}

void LuckyBlock::update(){
    animation();

    if(_dy < 0) { _hit_box.top -= 1; ++_tick_counter; _dy += 1; }
    else if(_tick_counter != 0) { _hit_box.top += 1; --_tick_counter; }

    _sprite.setPosition(_hit_box.left - offsetX, _hit_box.top);
}

void LuckyBlock::animation() {
    _current_frame += 0.08;
    if(_current_frame > 3) _current_frame -= 3;

    if(_is_coin) _sprite.setTextureRect(sf::IntRect(298 + (int)_current_frame * (texture_size+1), 78,
                                                     texture_size,texture_size));
    else {
        _sprite.setTextureRect(sf::IntRect(349, 78, texture_size,
                                           texture_size));
    }
}

void LuckyBlock::collision(int){
    if(_is_coin) { _dy = -6; notify(*this, oEvent::COIN_FALL); }
    _is_coin = false;
}

