#include<SDL.h>
#include "drawing.hpp"
#include "life.hpp"
#pragma once

class personLives: public Life{
    int identity=0;
    public:
    int *ptr;
    int get_identity() override;
    void draw();
    int update_lives();
    int get_lives();
    void set_lives();
    void set_l_p();
    personLives();
    personLives(int w, int x);
    //~personLives();
};