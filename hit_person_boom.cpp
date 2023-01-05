#include "hit_person_boom.hpp"

void Boom::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

Boom::Boom(){

}
Boom::Boom(int a, int b){
        // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {953,1528,558,566};

    // it will display pigeon on x = a, y = b location, the size of pigeon is 50 width, 50 height
    moverRect = {a, b, 150, 150};
}  
