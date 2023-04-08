//
// Created by Khanh Nguyen on 1/16/23.
//

#ifndef ICECREAMGAME2_POSITION_H
#define ICECREAMGAME2_POSITION_H


#include <SFML/Graphics.hpp>

class Position
{
public:
    template <class T>
    static void top(T& obj1, T& obj2);

    template <class T>
    static void center(T& obj1, T& obj2);

};

#include "Position.cpp"
#endif //ICECREAMGAME2_POSITION_CPP
