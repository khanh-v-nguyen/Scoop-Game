//
// Created by Khanh Nguyen on 1/16/23.
//

#include "FallingScoop.h"
sf::Texture FallingScoop::scoopTexture;

FallingScoop::FallingScoop()
{
    init();
}

FallingScoop::FallingScoop(sf::RenderWindow &window) : windowSize(window.getSize())
{
    init();
}

void FallingScoop::init()
{
    setUpScoop();
}

void FallingScoop::setUpScoop()
{
    fallingScoop.setRadius(40);
    scoopTexture.loadFromFile("images/pink scoop.png");
    fallingScoop.setTexture(&scoopTexture);

}

void FallingScoop::fallingEventHandler(sf::RenderWindow &window)
{
    fallingScoop.move({0,2});
    randomPos = rand() % window.getSize().x - fallingScoop.getRadius();

    if(fallingScoop.getPosition().y > window.getSize().y)
    {
        resetPosition();
    }
}

void FallingScoop::resetPosition()
{
    if(fallingScoop.getPosition().y > windowSize.y)
    {
        fallingScoop.setPosition({static_cast<float>(randomPos),0});
    }
}

sf::Vector2f FallingScoop::getPosition()
{
    return fallingScoop.getPosition();
}

sf::FloatRect FallingScoop::getGlobalBounds()
{
    return fallingScoop.getGlobalBounds();
}

void FallingScoop::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(fallingScoop);
}
