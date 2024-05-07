#include "Effects.h"
#include <iostream>

Effects::Effects() {
    sf::Image image;
    sf::Texture texture;

    image.loadFromFile("items_set.png");
    image.createMaskFromColor(sf::Color(146, 144, 255));
    texture.loadFromImage(image);

    _sprite.setTexture(texture);
}

void Effects::onNotify(const Creature &creature, oEvent event){
    switch(event){
        case oEvent::COIN_EFFECT:
            _coordinates.x = creature.getHitBox().left;
            _coordinates.y = creature.getHitBox().top + tile_size;
    }
}

