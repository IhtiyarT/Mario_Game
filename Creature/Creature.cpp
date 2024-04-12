#include "Creature.h"

using namespace sf;

Creature::Creature(sf::Texture &image)
{
    _sprite.setTexture(image);
    _sprite.setScale(Vector2f(2, 2));
    _dx = _dy = 0;
    _current_frame = 0;
}