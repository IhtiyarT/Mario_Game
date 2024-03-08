#ifndef MARIO_GAME_PLAYER_H
#define MARIO_GAME_PLAYER_H
#include <SFML/Graphics.hpp>

#define texture_size 16
#define tile_size 32
#define sizeX 1280
#define sizeY 720

class Player{
public:
    float dx, dy;
    sf::FloatRect rect;
    bool onGround;
    sf::Sprite sprite;
    float currentFrame;
    Player(sf::Texture &image);
    void update(float time, float& offsetX, float& offsetY);
    friend void playerCollision(Player &, int);
};



#endif //MARIO_GAME_PLAYER_H
