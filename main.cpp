#include "GameLogic.h"
using namespace sf;

int main(){
    bool run{true};
    while(run) run = startGame();
    return 0;
}

//TODO замутить смерть персонажа и победу через паттерн Наблюдатель
