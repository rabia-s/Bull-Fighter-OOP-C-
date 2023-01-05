#include "knife.hpp"

#include <iostream>
//#include "banda.hpp"

void Knife::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

Knife::Knife(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    //srcRect = {317,73,320,68};
    srcRect = {1191,348,702,149};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 50 height
    moverRect = {300, 40, 100, 20};
}
Knife::Knife(int a, int b){
        // src coorinates from assets.png file, they have been found using spritecow.com

    srcRect = {1191,348,702,149};

    moverRect = {a, b, 100, 20};
} 


void Knife:: move(){
    moverRect.x+= 20;
}
int Knife::get_knife_x(){
    int xx;
    xx= moverRect.x;
    //std::cout << std::endl << "left   " << moverRect.x;
    return xx;
}
int Knife::get_knife_y(){
    int yy;
    yy=moverRect.y;
    //std::cout << std::endl << " yyy "<< moverRect.y;
    return yy;
}
void Knife::operator -(){
    num_knife--;
}

