#include "life.hpp"
#include <SDL.h>
#include <iostream>
#pragma once

Life::Life(){ //parent class constructor
    
};

void Life::set_l(){
    lives_no=4;
}
int Life::get_lives(){
    //return this-> lives_no;   
}
void Life::set_lives(){
    
    // if (number_lives-1==0){
    //    // std::cout << " game over ";
    // }
    // else{
    //     number_lives-=1;
    //     int left;
    //     left= get_lives();
    //     std::cout<< " lives left: " << left;
    //     //std::cout << "lives gone gone "<< number_lives << "  ";
    // }
}

int Life::update_lives(){
    // if (number_lives-1==0){
    //    // std::cout << " game over ";
    // }
    // else{
    //     number_lives-=1;
    //     //std::cout << "lives gone gone "<< number_lives << "  ";
    // }
    return 0;
}
int Life::get_identity(){
    return 1234;
}
// Drawing object
void Life::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    //fly();
}
void Life::operator -(){
    number_lives--;
}
