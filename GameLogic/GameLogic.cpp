#include "GameLogic.h"
#include "map.h"
using namespace sf;

float offsetX=0;


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

        player.playerMoves(offsetX);

        win.clear(Color(20, 170, 255));

        player.update(time, offsetX);
        enemy.update(time, offsetX);

        mapRendering(win, cCurrentPath);

        if(player.getHitBox().intersects(enemy.getHitBox()) && enemy.getLife() && player.getDy() > 0) enemy.setLife();

        win.draw(player.getSprite());
        win.draw(enemy.getSprite());
        win.display();
    }
}

void mapRendering(sf::RenderWindow &win, const char *cCurrentPath){
    Texture texture;
    texture.loadFromFile(cCurrentPath);
    Sprite tyle(texture);
    for(size_t i=0;i<Height; ++i) {
        for (size_t j = 0; j < Width; ++j) {
            if (TileMap[i][j] == 'B') {
                tyle.setTextureRect(IntRect(143 - texture_size * 3, 112,
                                            texture_size, texture_size));
                tyle.setScale(Vector2f(2.13, 2.1));
            }
            if (TileMap[i][j] == '0') {
                tyle.setTextureRect(IntRect(127, 112, texture_size+1,
                                            texture_size));
                tyle.setScale(Vector2f(2.13, 2.1));
            }
            if (TileMap[i][j] == 'K') {
                tyle.setTextureRect(IntRect(46, 58, 47, 24));
                tyle.setScale(Vector2f(2, 2));
                tyle.setPosition(j * tile_size-offsetX, i * tile_size-8);
                win.draw(tyle);
                continue;
            }
            if (TileMap[i][j] == 'C') {
                tyle.setTextureRect(IntRect(97, 223, 45, 33));
                tyle.setScale(Vector2f(2.5,  2.5));
            }
            if (TileMap[i][j] == 'G'){
                tyle.setTextureRect(IntRect(145, 222, 76, 34));
                tyle.setScale(Vector2f(2.5, 2.5));
            }
            if (TileMap[i][j] == 'T'){
                tyle.setTextureRect(IntRect(0, 48, 32, 24));
                tyle.setScale(Vector2f(2.5, 2.66));
            }
            if (TileMap[i][j] == 't'){
                tyle.setTextureRect(IntRect(0, 72, 32, 24));
                tyle.setScale(Vector2f(2.5, 2.66));
            }
            if (TileMap[i][j] == 'W') continue;
            if (TileMap[i][j] == ' ') continue;


            tyle.setPosition(j * tile_size-offsetX, i * tile_size);
            win.draw(tyle);
        }
    }
}


