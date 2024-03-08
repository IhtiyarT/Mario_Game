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
    sf::RenderWindow win(sf::VideoMode(sizeX, sizeY), "Mario.exe");
    while(win.isOpen()){
        Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        win.clear(Color::Black);

        Texture texture;
        texture.loadFromFile("C:/Users/DELL/CLionProjects/Mario_Game/Mario_tileset.png");
        Sprite rect(texture);
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

        win.display();
    }
}



