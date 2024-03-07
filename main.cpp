#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow win(VideoMode(1280, 720), "SFML works!");
    CircleShape shape;
    shape.setRadius(50);
    shape.setPosition(10, 10);
    shape.setFillColor(Color::Red);
    while(win.isOpen()){
        Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        win.clear(Color::White);
        win.draw(shape);
        win.display();
    }
    return 0;
}
