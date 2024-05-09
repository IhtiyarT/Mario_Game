#ifndef MARIO_GAME_SPRITECONTAINER_H
#define MARIO_GAME_SPRITECONTAINER_H


struct SpriteContainer{
    SpriteContainer(sf::Sprite &sprite, float current_frame) : _sprite{sprite}, _current_frame{current_frame}{}
    sf::Sprite _sprite;
    float _current_frame{};
    virtual void stateUpdate() = 0;
};

struct CoinContainer : SpriteContainer
{
    CoinContainer(sf::Sprite sprite, float current_frame) : SpriteContainer(sprite, current_frame){}
    void stateUpdate()override{
        _current_frame += 0.02;

        _sprite.setTextureRect(sf::IntRect(180 + int(_current_frame)%3*10, 36,
                                          8, 16));

        float direction = int(_current_frame) > 3 ? 1 : -1;

        _sprite.setPosition(_sprite.getPosition().x,
                           _sprite.getPosition().y + direction);
    }
};

struct DiedMarioContainer : SpriteContainer{
    DiedMarioContainer(sf::Sprite sprite, float current_frame) : SpriteContainer(sprite, current_frame){}
    void stateUpdate()override{
        _current_frame += 0.01;

        float direction = int(_current_frame) > 0 ? 0.5 : -0.5;

        _sprite.setPosition(_sprite.getPosition().x,
                            _sprite.getPosition().y + direction);
    }
};


#endif //MARIO_GAME_SPRITECONTAINER_H
