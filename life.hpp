#include "SDL.h"
#include "drawing.hpp"
#pragma once

class Life{
    protected:
    
    int lives_no;
    SDL_Rect srcRect, moverRect;

    public:
    virtual int get_identity();
    int number_lives=4;
    void draw();
    void set_l();
    virtual int get_lives();
    virtual void set_lives();
    virtual int update_lives(); // making update_lives() virtual because its different for bull and the player
    Life();
    void operator-();
    //virtual ~Life();

};