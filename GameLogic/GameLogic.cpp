#include "GameLogic.h"
#include "map.h"
using namespace sf;

float offsetX=0, offsetY=0;


void windowRendering(){
    char cCurrentPath[FILENAME_MAX];

    GetCurrentDir(cCurrentPath, sizeof(cCurrentPath));

    Clock clock;

    sf::RenderWindow win(sf::VideoMode(sizeX, sizeY), "Mario.exe");
    Texture texture;
    texture.loadFromFile(strcat(cCurrentPath, "/Mario_tileset.png"));
    Player player(texture);
    Enemy enemy(texture);

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
        enemy.update(time, offsetX, offsetY);

        mapRendering(win, cCurrentPath);

        win.draw(player.getSprite());
        win.draw(enemy.getSprite());
        win.display();
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
                tyle.setScale(Vector2f(3.195, 3.15));
            }
            if (TileMap[i][j] == '0') {
                tyle.setTextureRect(IntRect(143 - 16, 112, texture_size,
                                            texture_size));
                tyle.setScale(Vector2f(3, 3));
            }
            if (TileMap[i][j] == 'K') {
                tyle.setTextureRect(IntRect(46, 58, 47, 24));
                tyle.setScale(Vector2f(4.05, 4.35));
            }
            if (TileMap[i][j] == 'C') {
                tyle.setTextureRect(IntRect(97, 223, 45, 33));
                tyle.setScale(Vector2f(3.75, 3.75));
            }
            if (TileMap[i][j] == 'W') continue;
            if (TileMap[i][j] == ' ') continue;

            tyle.setPosition(j * tile_size-offsetX, i * tile_size-offsetY);
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
