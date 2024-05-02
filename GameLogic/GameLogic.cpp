#include "GameLogic.h"
#include "map.h"
using namespace sf;

float offsetX=34;


void windowRendering(){
    char cCurrentPath[FILENAME_MAX];
    GetCurrentDir(cCurrentPath, sizeof(cCurrentPath));
    std::string current_path = cCurrentPath;

    Clock clock;

    sf::RenderWindow win(sf::VideoMode(sizeX, sizeY), "Mario.exe");
    Texture texture;
    texture.loadFromFile(current_path + "/Mario_tileset.png");
    std::cout << current_path;
    Player player(texture);
    Enemy enemy(texture);

    while(win.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        time /= 450;
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

        mapRendering(win, current_path);

        if(player.getHitBox().intersects(enemy.getHitBox()) && enemy.getLife() && player.getDy() > 0) enemy.setLife();

        win.draw(player.getSprite());
        win.draw(enemy.getSprite());
        win.display();
    }
}

void mapRendering(sf::RenderWindow &win, std::string current_path){
    Texture main_texture;
    Texture sec_texture;

    Image tile_set;
    tile_set.loadFromFile(current_path + "/Tileset.png");
    tile_set.createMaskFromColor(sf::Color(148, 148, 255));
    tile_set.createMaskFromColor(sf::Color(0, 41, 140));

    main_texture.loadFromFile(current_path + "/Mario_tileset.png");
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
            if (TileMap[i][j] == 'b') {
                tyle.setTextureRect(IntRect(143, 112,
                                            texture_size, texture_size));
                tyle.setScale(Vector2f(2.13, 2.1));
            }
            if (TileMap[i][j] == '0') {
                tyle.setTextureRect(IntRect(127, 112, texture_size+1,
                                            texture_size));
                tyle.setScale(Vector2f(2.13, 2.1));
            }
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
            if (TileMap[i][j] == 'W') continue;
            if (TileMap[i][j] == ' ') continue;


            tyle.setPosition(j * tile_size-offsetX, i * tile_size);
            win.draw(tyle);
        }
    }
}


