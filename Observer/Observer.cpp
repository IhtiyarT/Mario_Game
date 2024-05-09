#include "Observer.h"

void Subject::addObserver(Observer *observer){
    _observers.push_back(observer);
}

void Subject::removeObserver(Observer *observer){
    for(auto iter = _observers.begin();iter!=_observers.end();){
        if(*iter == observer) {
            _observers.erase(iter);
            return;
        }
    }
}

void Subject::notify(const Creature &creature, oEvent event){
    for(Observer *obs : _observers){
        obs->onNotify(creature, event);
    }
}