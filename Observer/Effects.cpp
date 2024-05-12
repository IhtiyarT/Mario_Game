#include "Effects.h"
#include "GameLogic.h"

Effects::Effects(sf::RenderWindow &win) : _win{&win}
{
    sf::Image image;

    if(!image.loadFromFile("items_set.png")) std::cout << "Error! set of items";
    image.createMaskFromColor(sf::Color(146, 144, 255));
    _items_texture.loadFromImage(image);

    if(!_mario_texture.loadFromFile("mario.png")) std::cout << "Error! set of mario";

    _sprite.setScale(sf::Vector2f(2, 2));
}

void Effects::onNotify(const Creature &creature, oEvent event){
    switch(event){
        case oEvent::COIN_FALL:
            _sprite.setTexture(_items_texture);
            _sprite.setTextureRect(sf::IntRect(180, 36, texture_size/2, texture_size));
            _sprite.setPosition(creature.getHitBox().left + 5, creature.getHitBox().top - tile_size);
            _effects_to_draw.push_back(new CoinContainer(_sprite));
            break;
        case oEvent::PLAYER_DIED:
            _sprite.setTexture(_mario_texture);
            _sprite.setTextureRect(sf::IntRect(0, 15, texture_size, texture_size));
            _sprite.setPosition(creature.getHitBox().left + 10 - offsetX, creature.getHitBox().top - tile_size);
            _effects_to_draw.push_back(new DiedMarioContainer(_sprite));
            break;
    }
}

void Effects::update(){
    for(iterator = _effects_to_draw.begin();iterator!=_effects_to_draw.end();++iterator) {
        (*iterator)->stateUpdate(offsetX);
        _win->draw((*iterator)->_sprite);
        if(int((*iterator)->_current_frame) == 7) iterator = _effects_to_draw.erase(iterator);
    }
}
