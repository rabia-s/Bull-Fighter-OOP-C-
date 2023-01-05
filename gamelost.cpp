#include "gamelost.hpp"

void GameLost::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

GameLost::GameLost(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {380,3267,661,485};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 50 height
    moverRect = {300, 500, 500, 500};
}
GameLost::GameLost(int a, int b){
        // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {380,3267,661,485};

    // it will display pigeon on x = a, y = b location, the size of pigeon is 50 width, 50 height
    moverRect = {a, b, 400, 400};
}  
