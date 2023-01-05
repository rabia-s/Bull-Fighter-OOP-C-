#include<SDL.h>
#include "drawing.hpp"

class Knife{

    SDL_Rect srcRect, moverRect;

public:
    int num_knife=3;
    void draw();
    // void fly(int a);
    void move();
    int get_knife_x();
    int get_knife_y();
    //void findBanda();
    
    Knife();

    // you may add other overloaded constructors here... 
    Knife(int a, int b);
    void operator -();
    int animation=0;
};