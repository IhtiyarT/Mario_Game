#include "GameLogic.h"

using namespace sf;

const double MS_PER_UPDATE = 16;

Game::Game() : _win(sf::VideoMode(sizeX, sizeY), "Mario.exe"), _effects(_win)
{
    _music.openFromFile("assets/sound/bgm.wav");
    _music.play();
    _music.setLoop(true);
}

Game::~Game(){
    for(auto iter : _entities) delete iter;
}


bool startGame(){
    Game game;
    offsetX = 34;
    return game.windowRendering();
}

bool Game::windowRendering(){
    Texture main_texture;
    Texture sec_texture;
    Texture mario_texture;

    Image tile_set;
    tile_set.loadFromFile("Tileset.png");
    tile_set.createMaskFromColor(sf::Color(148, 148, 255));
    tile_set.createMaskFromColor(sf::Color(0, 41, 140));

    main_texture.loadFromFile("Mario_tileset.png");
    sec_texture.loadFromImage(tile_set);
    mario_texture.loadFromFile("mario.png");

    Player player(mario_texture, _effects);

    std::list<Creature*> temp;
    getEntities(_entities, main_texture, sec_texture);

    auto iter = _entities.begin();

    double timer = 0;
    int counter = 0;
    Clock clock;
    double previous = clock.getElapsedTime().asMilliseconds();
    double lag = 0.0;
    while(_win.isOpen()){
        double current = clock.getElapsedTime().asMilliseconds();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;
        Event event;
        while (_win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _win.close();
        }

        _win.clear(Color(20, 170, 255));

        while(lag >= MS_PER_UPDATE) {
            for(iter=_entities.begin(); iter != _entities.end();){
                if(player.getHitBox().intersects((*iter)->getHitBox()) && (*iter)->getLife()){
                    if ((*iter)->getName() == "Block") {
                        checkBlock(**iter);
                        (*iter)->collision(3);
                        player.turnBack();
                    }
                    if((*iter)->getName() == "Bonus"){
                        (*iter)->collision(3);
                        player.setBig(true);
                    }
                    if((*iter)->getName() == "Enemy" && player.getDy() != 0) {
                        (*iter)->setLife(false);
                        (*iter)->setDx(0);
                        player.setDy(-1);
                        temp.push_back(*iter);
                    }
                    else if((*iter)->getName() == "Enemy") player.enemyIntersect();
                }
                (*iter)->update();
                if(!(*iter)->getLife()){ iter = _entities.erase(iter);}
                else ++iter;
            }
            player.update();
            lag -= MS_PER_UPDATE;
        }
        mapRendering(_win, main_texture, sec_texture);

        _effects.update();
        for(iter=_entities.begin(); iter != _entities.end(); ++iter) {
            _win.draw((*iter)->getSprite());
        }
        if(player.getLife()) _win.draw(player.getSprite());
        else timer+=0.25;

        if(!temp.empty()) {
            for (iter = temp.begin(); iter != temp.end(); ++iter) _win.draw((*iter)->getSprite());
            ++counter;
        }
        if(counter == 200) { delete *temp.begin(); temp.pop_front(); counter = 0;}

        _win.display();
        if(timer > 600) return true;
        if(Keyboard::isKeyPressed(sf::Keyboard::Key::Tab)) return true;
        if(Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) return false;
    }
    return false;
}

void Game::getEntities(std::list<Creature*> &list, const sf::Texture &main_texture, const sf::Texture &sec_texture){
    for(int i=0;i<Height;++i){
        for(int j=0;j<Width;++j){
            switch(TileMap[i][j]){
                case 'g':
                    list.push_back(new Enemy(main_texture, "Enemy", j*tile_size,
                                             i*tile_size, tile_size-5, 0, 0));
                    break;
                case 'b':
                    list.push_back(new BrickBlock(main_texture,
                                                  j*tile_size, i*tile_size, _effects));
                    break;
                case '0':
                    list.push_back(new LuckyBlock(sec_texture,
                                                  j*tile_size, i*tile_size, _effects));
                    break;
                case 'm':
                    list.push_back(new MushroomBlock(sec_texture,
                                                     j*tile_size, i*tile_size, _effects));
                    break;
            }
        }
    }
}

void Game::checkBlock(const Creature &creature) {
    sf::Vector2<int> position(creature.getHitBox().left / tile_size, creature.getHitBox().top / tile_size);
    if(TileMap[position.y][position.x] == 'm' && creature.getFrame() < 3) _entities.push_front(
            new Mushroom(creature.getHitBox().left, creature.getHitBox().top));
}


void Game::mapRendering(sf::RenderWindow &win, const sf::Texture &main_texture, const sf::Texture &sec_texture){
    Sprite tyle(main_texture);
    Sprite sec_tyle(sec_texture);

    for(size_t i=0;i<Height; ++i) {
        for (size_t j = 0; j < Width; ++j) {
            switch(TileMap[i][j]){
                case 'k':
                    tyle.setTextureRect(IntRect(46, 58, 47, 24));
                    tyle.setScale(Vector2f(2, 2));
                    tyle.setPosition(j * tile_size-offsetX, i * tile_size-8);
                    win.draw(tyle);
                    continue;
                case 'K':
                    tyle.setTextureRect(IntRect(4, 106, 70, 24));
                    tyle.setScale(Vector2f(2, 2));
                    tyle.setPosition(j * tile_size-offsetX, i * tile_size-8);
                    win.draw(tyle);
                    continue;
                case '2':
                    tyle.setTextureRect(IntRect(160, 122, 63, 21));
                    tyle.setScale(Vector2f(2, 2));
                    tyle.setPosition(j * tile_size-offsetX, i * tile_size-8);
                    win.draw(tyle);
                    continue;
                case 'I':
                    sec_tyle.setTextureRect(IntRect(0, 588, 16, 176));
                    sec_tyle.setScale(Vector2f(2, 2));
                    sec_tyle.setPosition(j * tile_size-offsetX + 2, i * tile_size - 32);
                    win.draw(sec_tyle);
                    continue;
                case 'Z':
                    sec_tyle.setTextureRect(IntRect(400, 588, 144, 176));
                    sec_tyle.setScale(Vector2f(2, 2));
                    sec_tyle.setPosition(j * tile_size-offsetX + 2, i * tile_size - 32);
                    win.draw(sec_tyle);
                    continue;
                case 'H':
                    tyle.setTextureRect(IntRect(145, 222, 76, 34));
                    tyle.setScale(Vector2f(2, 2));
                    tyle.setPosition(j * tile_size-offsetX, i * tile_size-4);
                    win.draw(tyle);
                    continue;
                case 'h':
                    tyle.setTextureRect(IntRect(0, 139, 48, 20));
                    tyle.setScale(Vector2f(2, 2));
                    tyle.setPosition(j * tile_size-offsetX, i * tile_size-8);
                    win.draw(tyle);
                    continue;
                case 'B':
                    tyle.setTextureRect(IntRect(143 - texture_size * 3, 112,
                                                texture_size, texture_size));
                    tyle.setScale(Vector2f(2.13, 2.1));
                    break;
                case 's':
                    tyle.setTextureRect(IntRect(143 - texture_size * 2, 112,
                                                texture_size, texture_size));
                    tyle.setScale(Vector2f(2.13, 2.1));
                    break;
                case 'c':
                    tyle.setTextureRect(IntRect(97, 223, 45, 33));
                    tyle.setScale(Vector2f(2,  2));
                    break;
                case 'C':
                    tyle.setTextureRect(IntRect(96, 160, 64, 32));
                    tyle.setScale(Vector2f(2,  2));
                    break;
                case '3':
                    tyle.setTextureRect(IntRect(5, 224, 85, 32));
                    tyle.setScale(Vector2f(2,  2));
                    break;
                case 'T':
                    tyle.setTextureRect(IntRect(0, 48, 32, 24));
                    tyle.setScale(Vector2f(2.5, 2.66));
                    break;
                case 't':
                    tyle.setTextureRect(IntRect(0, 72, 32, 24));
                    tyle.setScale(Vector2f(2.5, 2.66));
                    break;
                default:
                    continue;
            }

            tyle.setPosition(j * tile_size-offsetX, i * tile_size);
            win.draw(tyle);
        }
    }
}
