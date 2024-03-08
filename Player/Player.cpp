#include "Player.h"
using namespace sf;

Player::Player(sf::Texture &image) {
    sprite.setTexture(image);
    sprite.setScale(Vector2f(2, 2));
    rect = FloatRect(100, 128, tile_size, tile_size);
    sprite.setTextureRect(IntRect(112, 144, texture_size, texture_size));

    dx = dy = 0;
    onGround = false;
    currentFrame = 0;
}

void Player::update(float time, float& offsetX, float& offsetY){
    rect.left += dx*time;
    playerCollision(*this, 0);

    if(!onGround) dy = dy + 0.0005 * time;
    rect.top += dy*time;
    onGround = false;
    playerCollision(*this, 1);

    currentFrame += 0.005*time;
    if(currentFrame > 3) currentFrame -= 3;

    if(dx>0) sprite.setTextureRect(IntRect(112 + 31*int(currentFrame), 144, texture_size, texture_size));
    if(dx<0) sprite.setTextureRect(IntRect(112 + 31*int(currentFrame)+texture_size, 144, -texture_size, texture_size));

    sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

    dx = 0;
}