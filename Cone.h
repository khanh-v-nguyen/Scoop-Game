//
// Created by Khanh Nguyen on 1/16/23.
//

#ifndef ICECREAMGAME2_CONE_H
#define ICECREAMGAME2_CONE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "FallingScoop.h"
#include "Position.h"

class Cone : public sf::Drawable
{
public:
    Cone();
    std::vector<sf::CircleShape> coneStack;
    sf::CircleShape cone;
    static sf::Texture scoopTexture;
    static sf::Texture coneTexture;

    bool isTop;
    void setUpCone();
    void setUpStack();
    void eventHandler(FallingScoop &fallingScoop);
    bool reachTop();
    static int scoopCount;

    friend std::ostream& operator << (std::ostream &outs, const Cone &cone);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};


#endif //ICECREAMGAME2_CONE_H
