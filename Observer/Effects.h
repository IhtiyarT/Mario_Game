#ifndef MARIO_GAME_EFFECTS_H
#define MARIO_GAME_EFFECTS_H

#include "Observer.h"
#include <list>
#include <thread>
#include <iostream>
#include "SpriteContainer.h"

class Effects : public Observer
{
public:
    explicit Effects(sf::RenderWindow &win);
    void update();
    void pushBack();
    void onNotify(const Creature &creature, oEvent event)override;
private:
    sf::Sprite _sprite;
    sf::RenderWindow *_win;
    sf::Texture _texture;
    std::list<SpriteContainer*> _effects_to_draw;
    std::list<SpriteContainer*>::iterator iterator;
};



#endif //MARIO_GAME_EFFECTS_H
