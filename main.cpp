#include <iostream>
#include "SFML/Graphics.hpp"

int main() {

    int SENSIBILITY=5;

    sf::RenderWindow window(sf::VideoMode(1500,900),"Game");
    sf::Sprite sprite1;
    sf::Texture texture1;

    texture1.loadFromFile("/home/ale/CLionProjects/sprite/zelda.png");

    sprite1.setTexture(texture1);
    sprite1.setTextureRect(sf::IntRect(10,280,80,80));
    sprite1.setColor(sf::Color::White);
    sprite1.setPosition(sf::Vector2f(50,50));

    int LEFT=0;
    int RIGHT=0;

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){

            if(event.type==sf::Event::Closed)
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                if(LEFT%2==0)
                sprite1.setTextureRect(sf::IntRect(360,10,80,80));
                else
                sprite1.setTextureRect(sf::IntRect(180,10,80,80));
                LEFT++;
                sprite1.move(-SENSIBILITY,0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                if(RIGHT%2==0)
                sprite1.setTextureRect(sf::IntRect(10,100,80,80));
                else
                sprite1.setTextureRect(sf::IntRect(190,100,80,80));
                RIGHT++;
                sprite1.move(SENSIBILITY,0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite1.setTextureRect(sf::IntRect(100,190,80,80));
                sprite1.move(0,-SENSIBILITY);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sprite1.setTextureRect(sf::IntRect(100,270,80,80));
                sprite1.move(0,SENSIBILITY);
            }
        }

        window.clear(sf::Color::White);

window.draw(sprite1);

        window.display();

    }

    return 0;
}