#ifndef MARIO_GAME_SOUNDS_H
#define MARIO_GAME_SOUNDS_H

#include "Observer.h"

class Sounds : public Observer
{
public:
    void onNotify(const Creature &creature, oEvent event)override;
private:
    sf::SoundBuffer sound_buf;
    sf::Sound sound;
};


#endif //MARIO_GAME_SOUNDS_H
