#include "drawing.hpp"
#include<SDL.h>

class Person{
    public:
    SDL_Rect srcRect, moverRect, srcRect2, moverRect2;
    bool hover=false;
    int hover_frames=10;
    int facing;
    // add the fly function here as well.
    void draw();
    void fly(int a);
    void fly(int a, int b);
    void move(int s);
    int Person_X();
    int Person_Y();
    int facing_direction();
    //bool check();//called in beescpp to check if the bees leave the frame ..
    Person(); // may add other overloaded constructors here... 
    Person(int P_x, int P_y);
    int animation=0;
    
};