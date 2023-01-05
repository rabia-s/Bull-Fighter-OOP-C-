#include<SDL.h>
#include "drawing.hpp"
class Boom{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    Boom();

    // you may add other overloaded constructors here... 
    Boom(int a, int b);
    int animation=0;
};