#ifndef MARIO_GAME_PLAYER_H
#define MARIO_GAME_PLAYER_H
#include <SFML/Graphics.hpp>

#define texture_size 16
#define tile_size 32
#define sizeX 1280
#define sizeY 720

class Player{
public:
    explicit Player(sf::Texture &image);
    void update(float time, float& offsetX, float& offsetY);
    friend void playerCollision(Player &, int);
    void setDx(float dx){_dx = dx;}
    void setDy(float dy){_dy = dy;}
    void setOnGround(bool on_ground){_on_ground = on_ground;}
    float getDx() const{return _dx;}
    float getDy() const{return _dy;}
    bool getOnGround() const{return _on_ground;}
    sf::FloatRect getHitBox() const{return _hit_box;}
    sf::Sprite getSprite() const{return _sprite;}
private:
    float _dx, _dy;
    sf::FloatRect _hit_box;
    bool _on_ground;
    sf::Sprite _sprite;
    float _current_frame;
};



#endif //MARIO_GAME_PLAYER_H
