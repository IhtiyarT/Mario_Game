#include "GameLogic.h"
using namespace sf;

void windowRendering(){

    sf::RenderWindow win(sf::VideoMode(sizeX, sizeY), "Mario.exe");
    Texture texture;
    texture.loadFromFile("Mario_tileset.png");
    Player player(texture);

    std::list<Creature*> entities;
    std::list<Creature*>::iterator iter;
    std::list<Creature*> temp;
    getEnemies(entities, texture);

    sf::Music music;
    music.openFromFile("assets/sound/bgm.wav");
    music.play();
    music.setLoop(true);

    int counter = 0;
    Clock clock;
    double previous = clock.getElapsedTime().asMilliseconds();
    double lag = 0.0;
    while(win.isOpen()){
        double current = clock.getElapsedTime().asMilliseconds();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;
        Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }

        win.clear(Color(20, 170, 255));

        while(lag >= MS_PER_UPDATE) {
            player.update(offsetX);
            for(iter=entities.begin();iter!=entities.end();){
                Creature *b = *iter;
                b->update(offsetX);
                if(!b->getLife()){iter = entities.erase(iter);}
                else ++iter;
            }
            lag -= MS_PER_UPDATE;

        }

        mapRendering(win);

        for(iter=entities.begin();iter!=entities.end();++iter) {
            win.draw((*iter)->getSprite());
            if (player.getHitBox().intersects((*iter)->getHitBox()) && (*iter)->getLife()){
                if((*iter)->getName() == "Mushroom") {
                    (*iter)->setLife(false);
                    (*iter)->setDx(0);
                    player.setDy(-0.2);
                    temp.push_back(*iter);
                }
                else if((*iter)->getName() == "Brick" || (*iter)->getName() == "Lucky" ) {
                    (*iter)->setDy(-5);
                    player.setDy(3);
                }
            }
        }
        win.draw(player.getSprite());
        if(!temp.empty()) {
            for (iter = temp.begin(); iter != temp.end(); ++iter) win.draw((*iter)->getSprite());
            ++counter;
        }
        if(counter == 15) { delete *temp.begin(); temp.pop_front(); counter = 0;}

        win.display();
    }
}

void mapRendering(sf::RenderWindow &win){
    Texture main_texture;
    Texture sec_texture;

    Image tile_set;
    tile_set.loadFromFile("Tileset.png");
    tile_set.createMaskFromColor(sf::Color(148, 148, 255));
    tile_set.createMaskFromColor(sf::Color(0, 41, 140));

    main_texture.loadFromFile("Mario_tileset.png");
    sec_texture.loadFromImage(tile_set);

    Sprite tyle(main_texture);
    Sprite sec_tyle(sec_texture);

    for(size_t i=0;i<Height; ++i) {
        for (size_t j = 0; j < Width; ++j) {
            if (TileMap[i][j] == 'B') {
                tyle.setTextureRect(IntRect(143 - texture_size * 3, 112,
                                            texture_size, texture_size));
                tyle.setScale(Vector2f(2.13, 2.1));
            }
            if (TileMap[i][j] == 's') {
                tyle.setTextureRect(IntRect(143 - texture_size * 2, 112,
                                            texture_size, texture_size));
                tyle.setScale(Vector2f(2.13, 2.1));
            }
//            if (TileMap[i][j] == 'b') {
//                tyle.setTextureRect(IntRect(143, 112,
//                                            texture_size, texture_size));
//                tyle.setScale(Vector2f(2.1, 2.1));
//            }
//            if (TileMap[i][j] == '0') {
//                tyle.setTextureRect(IntRect(127, 112, texture_size+1,
//                                            texture_size));
//                tyle.setScale(Vector2f(2.1, 2.1));
//            }
            if (TileMap[i][j] == 'k') {
                tyle.setTextureRect(IntRect(46, 58, 47, 24));
                tyle.setScale(Vector2f(2, 2));
                tyle.setPosition(j * tile_size-offsetX, i * tile_size-8);
                win.draw(tyle);
                continue;
            }
            if (TileMap[i][j] == 'K') {
                tyle.setTextureRect(IntRect(4, 106, 70, 24));
                tyle.setScale(Vector2f(2, 2));
                tyle.setPosition(j * tile_size-offsetX, i * tile_size-8);
                win.draw(tyle);
                continue;
            }
            if (TileMap[i][j] == '2') {
                tyle.setTextureRect(IntRect(160, 122, 63, 21));
                tyle.setScale(Vector2f(2, 2));
                tyle.setPosition(j * tile_size-offsetX, i * tile_size-8);
                win.draw(tyle);
                continue;
            }
            if (TileMap[i][j] == 'I') {
                sec_tyle.setTextureRect(IntRect(0, 588, 16, 176));
                sec_tyle.setScale(Vector2f(2, 2));
                sec_tyle.setPosition(j * tile_size-offsetX + 2, i * tile_size - 32);
                win.draw(sec_tyle);
                continue;
            }
            if (TileMap[i][j] == 'Z') {
                sec_tyle.setTextureRect(IntRect(400, 588, 144, 176));
                sec_tyle.setScale(Vector2f(2, 2));
                sec_tyle.setPosition(j * tile_size-offsetX + 2, i * tile_size - 32);
                win.draw(sec_tyle);
                continue;
            }
            if (TileMap[i][j] == 'c') {
                tyle.setTextureRect(IntRect(97, 223, 45, 33));
                tyle.setScale(Vector2f(2,  2));
            }
            if (TileMap[i][j] == 'C') {
                tyle.setTextureRect(IntRect(96, 160, 64, 32));
                tyle.setScale(Vector2f(2,  2));
            }
            if (TileMap[i][j] == '3') {
                tyle.setTextureRect(IntRect(5, 224, 85, 32));
                tyle.setScale(Vector2f(2,  2));
            }
            if (TileMap[i][j] == 'H'){
                tyle.setTextureRect(IntRect(145, 222, 76, 34));
                tyle.setScale(Vector2f(2, 2));
                tyle.setPosition(j * tile_size-offsetX, i * tile_size-4);
                win.draw(tyle);
                continue;
            }
            if (TileMap[i][j] == 'h'){
                tyle.setTextureRect(IntRect(0, 139, 48, 20));
                tyle.setScale(Vector2f(2, 2));
                tyle.setPosition(j * tile_size-offsetX, i * tile_size-8);
                win.draw(tyle);
                continue;
            }
            if (TileMap[i][j] == 'T'){
                tyle.setTextureRect(IntRect(0, 48, 32, 24));
                tyle.setScale(Vector2f(2.5, 2.66));
            }
            if (TileMap[i][j] == 't'){
                tyle.setTextureRect(IntRect(0, 72, 32, 24));
                tyle.setScale(Vector2f(2.5, 2.66));
            }
            if (TileMap[i][j] == 'W' || TileMap[i][j] == '0' || TileMap[i][j] == 'b') continue;
            if (TileMap[i][j] == ' ') continue;
            if (TileMap[i][j] == 'g') continue;

            tyle.setPosition(j * tile_size-offsetX, i * tile_size);
            win.draw(tyle);
        }
    }
}

void getEnemies(std::list<Creature*> &list, const sf::Texture &texture){
    for(int i=0;i<Height;++i){
        for(int j=0;j<Width;++j){
            if(TileMap[i][j] == 'g') list.push_back(new Enemy(texture, "Mushroom", j*tile_size,
                                          i*tile_size, tile_size-5, 0, 0));
            else if(TileMap[i][j] == 'b') list.push_back(new Block(texture, "Brick", j*tile_size, i*tile_size));
            else if(TileMap[i][j] == '0') list.push_back(new Block(texture, "Lucky", j*tile_size, i*tile_size));
        }
    }
}

