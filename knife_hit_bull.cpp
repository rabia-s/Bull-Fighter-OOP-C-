#include "knife_hit_bull.hpp"

void KnifeHit::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

KnifeHit::KnifeHit(){

}
KnifeHit::KnifeHit(int a, int b){
        // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {1418,3006,799,714};

    // it will display pigeon on x = a, y = b location, the size of pigeon is 50 width, 50 height
    moverRect = {a, b, 200, 150};
}  
