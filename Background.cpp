//
// Created by Khanh Nguyen on 1/16/23.
//

#include "Background.h"
sf::Texture Background::mapTexture;
sf::Font Background::pixelFont;

Background::Background()
{
    setUpMap();
}


Background::Background(std::string filename)
{
    loadFromFile(filename);
    setUpMap();
}

void Background::loadFromFile(const std::string &filename)
{
    std::ifstream fin; //create ifstream object
    std::string next;
    fin.open(filename);
    if (fin.fail())
        exit(20);

    while(getline(fin,next)) //third parameter is deliminator which is /n by default
    {
        textureStack.push(next); //putting all words from file into stack
    }
    fin.close();
}


void Background::setUpMap()
{
    map.setSize({600,600});

    scoreNumText.setCharacterSize(100);
    scoreNumText.setPosition({map.getSize().x / 2 - scoreNumText.getCharacterSize() /3, 0});

    scoreNumText.setColor(sf::Color::Blue);
    pixelFont.loadFromFile("CHERI___.TTF");
    scoreNumText.setFont(pixelFont);
}

void Background::eventHandler(Cone cone)
{
    mapTexture.loadFromFile(textureStack.top());
    map.setTexture(&mapTexture);
    scoreNumText.setString(std::to_string(Cone::scoopCount));

    if(cone.isTop && textureStack.size() > 1)
    {
        std::string temp = textureStack.top();
        textureStack.pop();
    }
}

void Background::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(map);
    target.draw(scoreNumText);
}


