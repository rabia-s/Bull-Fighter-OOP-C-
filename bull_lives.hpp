#include<SDL.h>
#include "drawing.hpp"
#include "life.hpp"
#pragma once

class bullLives: public Life{
    int identity=1;
    public:
    int get_identity() override;
    void draw();
    int update_lives();
    int get_lives();
    void set_lives();
    // int get_x_coordinate();
    // int get_y_coordinate();
    bullLives();
    bullLives(int w, int x);
    //~bullLives();
};