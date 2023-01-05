#include<SDL.h>
#include "drawing.hpp"
class GameWon{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    GameWon();

    // you may add other overloaded constructors here... 
    GameWon(int a, int b);
    int animation=0;
};