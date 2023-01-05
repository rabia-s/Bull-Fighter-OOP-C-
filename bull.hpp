#include<SDL.h>
#include "drawing.hpp"
#pragma once
class Bull{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void fly();
    void restart();
    Bull();
    int get_bull_x();
    int get_bull_y();

    // you may add other overloaded constructors here... 
    Bull(int a, int b);
    int animation=0;
};
