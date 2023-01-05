#include<SDL.h>
#include "drawing.hpp"
class KnifeHit{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    KnifeHit();

    // you may add other overloaded constructors here... 
    KnifeHit(int a, int b);
    int animation=0;
};