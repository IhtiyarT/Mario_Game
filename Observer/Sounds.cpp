#include "Sounds.h"

void Sounds::onNotify(const Creature &creature, oEvent event){
    std::string path = "../assets/sound/";
    switch(event){
        case oEvent::PLAYER_JUMP:
            sound_buf.loadFromFile(path + "jump.wav");
            sound.setBuffer(sound_buf);
            sound.play();
            return;
        case oEvent::MUSHROOM_DIED:
            sound_buf.loadFromFile(path + "hit.wav");
            sound.setBuffer(sound_buf);
            sound.play();
            return;
        case oEvent::PLAYER_DIED:
            sound_buf.loadFromFile(path + "die.wav");
            sound.setBuffer(sound_buf);
            sound.play();
            return;
        case oEvent::MUSHROOM_ATE:
            sound_buf.loadFromFile(path + "mushroom.wav");
            sound.setBuffer(sound_buf);
            sound.play();
            return;
        case oEvent::COIN_FALL:
            sound_buf.loadFromFile(path + "coin.wav");
            sound.setBuffer(sound_buf);
            sound.play();
            return;
    }
}

