#include "GameLogic.h"
#include "map.h"
using namespace sf;

float offsetX=0, offsetY=0;


void windowRendering(){
    char cCurrentPath[FILENAME_MAX];

    GetCurrentDir(cCurrentPath, sizeof(cCurrentPath));

    Clock clock;

    sf::RenderWindow win(sf::VideoMode(sizeX, sizeY), "Mario.exe");
    Texture texture1;
    texture1.loadFromFile(strcat(cCurrentPath, "/Mario_tileset.png"));
    Player player(texture1);

    while(win.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        time /= 650;
        clock.restart();
        Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }

        playerMoves(player);

        win.clear(Color(20, 170, 255));

        player.update(time, offsetX, offsetY);

        mapRendering(win, cCurrentPath);

        win.draw(player.getSprite());
        win.display();
    }
}

void playerCollision(Player &p, int dir){
    for (int i = p._hit_box.top / tile_size; i < (p._hit_box.top + p._hit_box.height) / tile_size; ++i){
        if(i>Height) break;
        for (int j= p._hit_box.left / tile_size; j < (p._hit_box.left + p._hit_box.width) / tile_size; ++j){
            if(TileMap[i][j] == 'B' || TileMap[i][j] == 'W'){
                if(p._dx > 0 && dir == 0) p._hit_box.left = j * tile_size - p._hit_box.width;
                if(p._dx < 0 && dir == 0) p._hit_box.left = j * tile_size + tile_size;
                if(p._dy > 0 && dir == 1){
                    p._hit_box.top = i * tile_size - p._hit_box.height;
                    p._dy = 0;
                    p._on_ground = true;
                }
                if (p._dy < 0 && dir == 1) { p._hit_box.top = i * tile_size + tile_size; p._dy = 0;}
            }
            if(TileMap[i][j]=='0'){
                TileMap[i][j] = ' ';
            }
        }
    }
}

void mapRendering(sf::RenderWindow &win, const char *cCurrentPath){
    Texture texture;
    texture.loadFromFile(cCurrentPath);
    Sprite tyle(texture);
    for(int i=0;i<Height; ++i) {
        for (int j = 0; j < Width; ++j) {
            if (TileMap[i][j] == 'B') {
                tyle.setTextureRect(IntRect(143 - texture_size * 3, 112,
                                            texture_size, texture_size));
                tyle.setScale(Vector2f(2.13, 2.1));
            }
            if (TileMap[i][j] == '0') {
                tyle.setTextureRect(IntRect(143 - 16, 112, texture_size,
                                            texture_size));
                tyle.setScale(Vector2f(2, 2));
            }
            if (TileMap[i][j] == 'K') {
                tyle.setTextureRect(IntRect(46, 58, 47, 24));
                tyle.setScale(Vector2f(2.7, 2.9));
            }
            if (TileMap[i][j] == 'C') {
                tyle.setTextureRect(IntRect(97, 223, 45, 33));
                tyle.setScale(Vector2f(2.5, 2.5));
            }
            if (TileMap[i][j] == 'W') continue;
            if (TileMap[i][j] == ' ') continue;

            tyle.setPosition(j * tile_size - offsetX, i * tile_size - offsetY);
            win.draw(tyle);
        }
    }
}

void playerMoves(Player &p){
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        p.setDx(-0.1);
    }
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        p.setDx(0.1);
    }
    if(Keyboard::isKeyPressed(Keyboard::Up)){
        if(p.getOnGround()){ p.setDy(-0.42); p.setOnGround(false);}
    }

    if(p.getHitBox().left > sizeX / 2) offsetX = p.getHitBox().left - sizeX / 2;
   // if(p._hit_box.top > sizeY/2) offsetY = p._hit_box.top - sizeY/2;
}
