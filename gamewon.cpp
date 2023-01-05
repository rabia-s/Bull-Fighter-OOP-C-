#include "gamewon.hpp"

void GameWon::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

GameWon::GameWon(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {1360,2244,630,453};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 50 height
    moverRect = {300, 500, 200, 200};
}
GameWon::GameWon(int a, int b){
        // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {331,2469,830,656};

    // it will display pigeon on x = a, y = b location, the size of pigeon is 50 width, 50 height
    moverRect = {a, b, 150, 150};
}  
