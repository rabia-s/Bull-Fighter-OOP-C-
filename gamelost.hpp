#include<SDL.h>
#include "drawing.hpp"
class GameLost{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    GameLost();

    // you may add other overloaded constructors here... 
    GameLost(int a, int b);
    int animation=0;
};