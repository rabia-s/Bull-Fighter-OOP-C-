#include "bull.hpp"
#include <iostream>

void Bull::draw(){ 
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    fly();
}

Bull::Bull(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {3803,182,992,549};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 50 height
    moverRect = {30, 40, 250, 150};
}
Bull::Bull(int a, int b){
        // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {3803,182,992,549};

    // it will display pigeon on x = a, y = b location, the size of pigeon is 50 width, 50 height
    moverRect = {a, b, 250, 150};
}
bool face_left=false;
bool game_restart=false;
void Bull::restart(){
    face_left==false;
    moverRect.x=0;
    animation=0;
    bool game_restart=true;
    srcRect = {3803,182,992,549};
    moverRect.x+=10;
}

void Bull:: fly(){
    
    if (moverRect.x==1000){
        face_left=true;
        animation=0;
    }
    
    if (face_left==true){
        if (animation == 0) { 
                srcRect = {2268,181,994,553}; 
                animation =animation+ 1; 
            } else if (animation == 1) {
                srcRect = {2182,812,1101,663}; 
                animation=animation+ 1; 
            } else {
                srcRect = {2209,1521,970,852}; 
                animation =0;
            }
        moverRect.x -= 10;
        if (moverRect.x==0){
            face_left=false;
        }
    }

    if (moverRect.x==0 || face_left==false || game_restart==true){
        if (animation == 0) { 
                srcRect = {3803,182,992,549}; //Change to sprite 1
                animation =animation+ 1; //increment counter to move to next frame
            } else if (animation == 1) {
                srcRect = {3783,812,1098,663}; //Change to sprite 2
                animation=animation+ 1; //increment counter to move to next frame
            } else {
                srcRect = {3888,1542,967,848}; //Change to sprite 3
                animation =0;
            }
        moverRect.x += 10;
        game_restart=false;
    }    
    
}
int Bull::get_bull_x(){
    int xx;
    xx= moverRect.x;
    //std::cout << std::endl << "left   " << moverRect.x;
    return xx;
}
int Bull::get_bull_y(){
    int yy;
    yy=moverRect.y;
    //std::cout << std::endl << " yyy "<< moverRect.y;
    return yy;
}