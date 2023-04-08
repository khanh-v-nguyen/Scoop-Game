//
// Created by Khanh Nguyen on 1/16/23.
//

#include "Cone.h"
sf::Texture Cone::scoopTexture;
sf::Texture Cone::coneTexture;
int Cone::scoopCount;

Cone::Cone()
{
    setUpCone();
    setUpStack();
}

void Cone::setUpStack()
{
    scoopTexture.loadFromFile("images/pink scoop.png");
    coneTexture.loadFromFile("images/waffle cone.png");

    cone.setTexture(&coneTexture);
    coneStack.push_back(cone);

}

void Cone::setUpCone()
{
    cone.setPosition({0,500});
    cone.setRadius(40);
}

void Cone::eventHandler(FallingScoop &fallingScoop)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        coneStack[0].move({-3,0});
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        coneStack[0].move({3,0});
    }

    sf::FloatRect c = coneStack.back().getGlobalBounds();
    sf::FloatRect f = fallingScoop.getGlobalBounds();

    if(f.intersects(c))
    {
        coneStack.push_back(sf::CircleShape(40));
        scoopCount += 1;
        fallingScoop.resetPosition();
    }

    for(int i = 1; i < coneStack.size(); i++)
    {
        Position::top(coneStack[i-1], coneStack[i]);
        coneStack.back().setTexture(&scoopTexture);
    }

    if(coneStack.back().getPosition().y <= 0)
    {
        for(int i = 1; i < coneStack.size(); i++)
        {
            coneStack.pop_back();
            coneStack.pop_back();
            scoopCount = 0;
            isTop = true;
        }
    }
    else
    {
        isTop = false;
    }
}

std::ostream& operator << (std::ostream &outs, const Cone &cone)
{
    return outs << cone.coneStack.size() - 1; //not including cone
}

void Cone::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(sf::CircleShape scoop : coneStack)
    {
        target.draw(scoop);
    }
}
