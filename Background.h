//
// Created by Khanh Nguyen on 1/16/23.
//

#ifndef ICECREAMGAME2_BACKGROUND_H
#define ICECREAMGAME2_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "Cone.h"
#include <fstream>
#include <string>
#include <stack>

class Background : public sf::Drawable
{
public:
    Background();
    Background(std::string filename);
    void loadFromFile(const std::string &filename);

    std::stack<std::string> textureStack;
    sf::RectangleShape map;
    static sf::Texture mapTexture;
    static sf::Font pixelFont;
    sf::Text scoreText;
    sf::Text scoreNumText;

    void setUpMap();
    void eventHandler(Cone cone);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //ICECREAMGAME2_BACKGROUND_H
