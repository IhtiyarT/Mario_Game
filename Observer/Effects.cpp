#include "Effects.h"
#include "GameLogic.h"

Effects::Effects(sf::RenderWindow &win) : _win{&win}
{
    sf::Image image;

    if(!image.loadFromFile("items_set.png")) std::cout << "Error! items in set";
    image.createMaskFromColor(sf::Color(146, 144, 255));
    _texture.loadFromImage(image);

    _sprite.setTexture(_texture);
    _sprite.setScale(sf::Vector2f(2, 2));
}

void Effects::onNotify(const Creature &creature, oEvent event){
    switch(event){
        case oEvent::COIN_EFFECT:
            _sprite.setTextureRect(sf::IntRect(180, 36, 8, 16));
            _sprite.setPosition(creature.getHitBox().left + 10 - offsetX, creature.getHitBox().top - tile_size);
            _effects_to_draw.push_back(new CoinContainer(_sprite, 0));
    }
}

void Effects::update(){
    for(iterator = _effects_to_draw.begin();iterator!=_effects_to_draw.end();++iterator) {
        (*iterator)->stateUpdate();
        _win->draw((*iterator)->_sprite);
        if(int((*iterator)->_current_frame) == 7) iterator = _effects_to_draw.erase(iterator);
    }
}

void Effects::pushBack(){

}
