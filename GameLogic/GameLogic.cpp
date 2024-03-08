#include "GameLogic.h"
using namespace sf;

float offsetX=0, offsetY=0;

sf::String TileMap[Height]{
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "B                                                                              BB",
        "B                000                                                           BB",
        "B                        BBBBBB                                                BB",
        "B                                                                            B BB",
        "B                                         BBBBBBB                            B BB",
        "B                      0                                                   BBB BB",
        "B                   BBBBB                                                      BB",
        "B                                                                              BB",
        "B             B              BBBBBB                                            BB",
        "B            B          00                          BBBBBBBBB                  BB",
        "B                                                                              BB",
        "B                                                                              BB",
        "B                B                         BBBBB                               BB",
        "B                           BBBBB                                              BB",
        "B                         BBBBBBB      B                                       BB",
        "B                       BBBBBBBBB                                              BB",
        "B                      BBBBBBBBBB                                              BB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};



void windowRendering(){
    Clock clock;

    sf::RenderWindow win(sf::VideoMode(sizeX, sizeY), "Mario.exe");
    Texture texture1;
    texture1.loadFromFile("C:/Users/DELL/CLionProjects/Mario_Game/Mario_tileset.png");
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

        win.clear(Color::Black);

        Texture texture;
        texture.loadFromFile("C:/Users/DELL/CLionProjects/Mario_Game/Mario_tileset.png");
        Sprite rect(texture);


        player.update(time, offsetX, offsetY);

        for(int i=0;i<Height; ++i) {
            for (int j = 0; j < Width; ++j) {
                if (TileMap[i][j] == 'B') {
                    rect.setTextureRect(IntRect(143 - texture_size * 3, 112,
                                                texture_size, texture_size));
                    rect.setScale(Vector2f(2, 2));
                }
                if (TileMap[i][j] == '0') {
                    rect.setTextureRect(IntRect(143-16,112,texture_size,texture_size));
                    rect.setScale(Vector2f(2, 2));
                }
                if (TileMap[i][j] == ' ') continue;

                rect.setPosition(j*tile_size - offsetX, i*tile_size-offsetY);
                win.draw(rect);
            }
        }

        win.draw(player.sprite);
        win.display();
    }
}

void playerCollision(Player &p, int dir){
    for (int i=p.rect.top/tile_size;i<(p.rect.top+p.rect.height)/tile_size;++i){
        for (int j=p.rect.left/tile_size;j<(p.rect.left+p.rect.width)/tile_size;++j){
            if(TileMap[i][j] == 'B'){
                if (p.dx > 0 && dir==0)  p.rect.left = j * tile_size - p.rect.width;
                if (p.dx < 0 && dir==0) p.rect.left = j * tile_size + tile_size;
                if (p.dy > 0 && dir==1) { p.rect.top = i * tile_size - p.rect.height; p.dy=0;p.onGround = true;}
                if (p.dy < 0 && dir==1) { p.rect.top = i * tile_size + tile_size; p.dy = 0; }
            }
            if(TileMap[i][j]=='0'){
                TileMap[i][j] = ' ';
            }
        }
    }
}

void playerMoves(Player &player){
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        player.dx = -0.1;
    }
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        player.dx = 0.1;
    }
    if(Keyboard::isKeyPressed(Keyboard::Up)){
        if(player.onGround){ player.dy = -0.42; player.onGround = false;}
    }

    if(player.rect.left > sizeX/2) offsetX = player.rect.left - sizeX/2;
    if(player.rect.top > sizeY/2) offsetY = player.rect.top - sizeY/2;
}
