//
// Created by Khanh Nguyen on 1/16/23.
//

#ifndef ICECREAMGAME2_FALLINGSCOOP_H
#define ICECREAMGAME2_FALLINGSCOOP_H
#include <iostream>
#include <SFML/Graphics.hpp>
class FallingScoop : public sf::Drawable
{
public:
    FallingScoop();
    FallingScoop(sf::RenderWindow &window);
    void init();

    sf::CircleShape fallingScoop;
    static sf::Texture scoopTexture;
    void setUpScoop();
    void fallingEventHandler(sf::RenderWindow &window);
    void resetPosition();

    sf::Vector2f windowSize;
    sf::FloatRect getGlobalBounds();
    int randomPos;
    sf::Vector2f getPosition();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //ICECREAMGAME2_FALLINGSCOOP_H
