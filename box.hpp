#include<SDL.h>
#include "drawing.hpp"
class Box{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    Box();

    // you may add other overloaded constructors here... 
    Box(int a, int b);
    int animation=0;
};