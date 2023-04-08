//
// Created by Khanh Nguyen on 1/16/23.
//

#ifndef ICECREAMGAME2_MOUSEEVENTS_H
#define ICECREAMGAME2_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>

class MouseEvents
{
public:
    template<class T>
    static bool isHovered(const T& Obj, const sf::RenderWindow& window);

    template<class T>
    static bool isClicked(const T& Obj, const sf::RenderWindow& window);

    template<class T>
    static bool isNotClicked(const T& Obj, const sf::RenderWindow& window);

};

#include "MouseEvents.cpp"
#endif //ICECREAMGAME2_MOUSEEVENTS_H
