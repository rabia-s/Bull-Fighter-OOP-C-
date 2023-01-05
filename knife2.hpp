#include<SDL.h>
#include "drawing.hpp"

class KnifeLeft{

    SDL_Rect srcRect, moverRect;

public:
    int num_knife=3;
    void draw();
    // void fly(int a);
    void move();
    int get_knife_x();
    int get_knife_y();
    //void findBanda();
    
    KnifeLeft();

    // you may add other overloaded constructors here... 
    KnifeLeft(int a, int b);
    int animation=0;
    void operator-();
};