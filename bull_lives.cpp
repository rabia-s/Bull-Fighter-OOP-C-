#include "bull_lives.hpp"
#include "drawing.hpp"
#include <iostream>
#pragma once

bullLives::bullLives(){
    srcRect = {16,143,636,547};
    moverRect = {30, 40, 50, 50};
}
bullLives::bullLives(int a, int b){
    srcRect = {16,143,636,547};
    moverRect = {a, b, 30, 30};
} 
// int get_x_coordinate(){
//     // int x= moverRect.x;
//     // return x;
// }
// int get_y_coordinate(){
//     // int y= moverRect.y;
//     // return y;
// }
int bullLives::get_identity(){
    return identity;
}
int bullLives:: update_lives(){
    if (number_lives-1==0){
        std::cout << " game over ";
        return 2;
    }
    else{
        number_lives-=1;
        std::cout << "lives gone gone "<< number_lives << "  ";
        return 0;
    }
}
int bullLives::get_lives(){
    return number_lives;   
}
void bullLives::set_lives(){
    
    if (number_lives-1==0){
       // std::cout << " game over ";
    }
    else{
        number_lives-=1;
        int left;
        left= get_lives();
        std::cout<< " bull lives left: " << left;
        //std::cout << "lives gone gone "<< number_lives << "  ";
    }
}
// bullLives::~bullLives(){
//     //cout<<"bull lives deleted"<<endl;
// }