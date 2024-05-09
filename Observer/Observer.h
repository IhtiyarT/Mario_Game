#ifndef MARIO_GAME_OBSERVER_H
#define MARIO_GAME_OBSERVER_H

#include "Creature.h"
#include "SFML/Audio.hpp"
#include <vector>

enum struct oEvent
{
    PLAYER_JUMP,
    MUSHROOM_DIED,
    COIN_FALL,
    PLAYER_DIED
};

class Observer {
public:
    virtual ~Observer(){}
    virtual void onNotify(const Creature &creature, oEvent event) = 0;
};

class Subject
{
private:
    std::vector<Observer*> _observers;
public:
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);
protected:
    void notify(const Creature &creature, oEvent event);
};


#endif //MARIO_GAME_OBSERVER_H
