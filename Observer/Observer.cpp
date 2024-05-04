#include "Observer.h"

void Subject::addObserver(Observer *observer){
    _observers.push_back(observer);
}

void Subject::removeObserver(Observer *observer){
    auto iter = _observers.begin();
    for(Observer *obs : _observers){
        if(obs == observer) _observers.erase(iter);
        else ++iter;
    }
}

void Subject::notify(const Creature &creature, oEvent event){
    for(Observer *obs : _observers){
        obs->onNotify(creature, event);
    }
}