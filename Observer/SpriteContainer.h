#ifndef MARIO_GAME_SPRITECONTAINER_H
#define MARIO_GAME_SPRITECONTAINER_H


struct SpriteContainer{
    explicit SpriteContainer(sf::Sprite &sprite) : _sprite{sprite}, _current_frame{0}{}
    sf::Sprite _sprite;
    float _current_frame;
    virtual void stateUpdate(float offsetX) = 0;
};

struct CoinContainer : SpriteContainer
{
    explicit CoinContainer(sf::Sprite sprite) : SpriteContainer(sprite){}
    void stateUpdate(float offsetX)override{
        _current_frame += 0.02;

        _sprite.setTextureRect(sf::IntRect(180 + int(_current_frame)%3*10, 36,
                                          8, 16));

        static float previous_offsetX = 0;
        float new_offsetX = offsetX - previous_offsetX;
        if(int(_current_frame) == 7) previous_offsetX = 0;
        else previous_offsetX = offsetX;

        float direction = int(_current_frame) > 3 ? 1 : -1;

        _sprite.setPosition(_sprite.getPosition().x - new_offsetX,
                           _sprite.getPosition().y + direction);
    }
};

struct DiedMarioContainer : SpriteContainer{
    explicit DiedMarioContainer(sf::Sprite sprite) : SpriteContainer(sprite){}
    void stateUpdate(float offsetX)override{
        _current_frame += 0.01;

        float direction = int(_current_frame) > 0 ? 0.5 : -0.5;

        _sprite.setPosition(_sprite.getPosition().x,
                            _sprite.getPosition().y + direction);
    }
};

#endif //MARIO_GAME_SPRITECONTAINER_H
