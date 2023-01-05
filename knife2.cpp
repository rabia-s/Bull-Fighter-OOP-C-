#include "knife2.hpp"

#include <iostream>
//#include "banda.hpp"

void KnifeLeft::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

KnifeLeft::KnifeLeft(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    //srcRect = {317,73,320,68};
    srcRect = {100,1034,637,136};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 50 height
    moverRect = {300, 40, 100, 20};
}
KnifeLeft::KnifeLeft(int a, int b){
        // src coorinates from assets.png file, they have been found using spritecow.com
    //srcRect = {317,73,320,68};
    //srcRect = {331,2469,830,656};
    srcRect = {100,1034,637,136};

    // it will display pigeon on x = a, y = b location, the size of pigeon is 50 width, 50 height
    moverRect = {a, b, 100, 20};
} 


void KnifeLeft:: move(){
    moverRect.x-= 20;
}
int KnifeLeft::get_knife_x(){
    int xx;
    xx= moverRect.x;
    //std::cout << std::endl << "left   " << moverRect.x;
    return xx;
}
int KnifeLeft::get_knife_y(){
    int yy;
    yy=moverRect.y;
    //std::cout << std::endl << " yyy "<< moverRect.y;
    return yy;
}
void KnifeLeft::operator -(){
    num_knife--;
}


