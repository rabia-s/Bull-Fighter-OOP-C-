#include "person_lives.hpp"
#include "drawing.hpp"
#pragma once
#include <iostream>

personLives::personLives(){
    srcRect = {16,143,636,547};
    moverRect = {30, 40, 50, 50};

}
personLives::personLives(int a, int b){
    srcRect = {16,143,636,547};
    moverRect = {a, b, 30, 30};
} 
int personLives::get_lives(){
    return number_lives;   
}
void personLives::set_lives(){
    
    if (number_lives-1==0){
       // std::cout << " game over ";
    }
    else{
        number_lives-=1;
        int left;
        left= get_lives();
        std::cout<< " person lives left: " << left;
        //std::cout << "lives gone gone "<< number_lives << "  ";
    }
}
int personLives:: get_identity(){
    return identity;
}
int personLives:: update_lives(){
    if (lives_no-1==0){
        std::cout << " game over ";
        return 1;
    }
    else{
        lives_no-=1;
        std::cout << "lives gone person "<< lives_no << "  ";
        return 0;
    }
}
void personLives::set_l_p(){
    set_l();
}
// personLives::~personLives(){
    
// }