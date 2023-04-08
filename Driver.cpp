//
// Created by Khanh Nguyen on 1/16/23.
//

#include "Driver.h"

void playGame()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(600, 600, 32), "Scoop!");
    window.setFramerateLimit(60);

    Background skyMap("mapTextures.txt");
    Cone cone;
    FallingScoop fallingScoop;

    while (window.isOpen()) {
        sf::Event event; // event
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(skyMap);
        skyMap.eventHandler(cone);

        fallingScoop.fallingEventHandler(window);
        window.draw(fallingScoop);

        cone.eventHandler(fallingScoop);
        window.draw(cone);

        window.display();
    }
    std::cout << cone;
}
