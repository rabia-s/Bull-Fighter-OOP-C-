#include "person.hpp"
#include <iostream>
bool isJumping= false;
bool isFalling= false;
bool tobox=false;
bool godown=false;
int jump= 0;
int jumpHeight=5;

 
// pigeon implementation will go here.
void Person::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    // SDL_RenderCopy(Drawing::gRenderer2, Drawing::assets3, &srcRect2, &moverRect2);
    fly(0);
}
Person::Person(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {88,3949,277,940};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 50 height
    moverRect = {30, 40, 100, 150};
}
Person::Person(int a, int b){
        // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {88,3949,277,940};

    // it will display pigeon on x = a, y = b location, the size of pigeon is 50 width, 50 height
    moverRect = {a, b, 100, 150};
}
int Person:: facing_direction(){
    return facing;
}
void Person:: move(int direction){
    if (direction==2){
        // left
        isJumping=true;
        isFalling=false;
        if (moverRect.x-10 >0){
            moverRect.x-= 30;
        }
        //if person is on top of box, bring him down
        if (moverRect.y>250 && moverRect.y<375){
            std::cout << moverRect.y << " y coord ";
            moverRect.x=1000;
            moverRect.y=450;
        }
        facing=2;
    }
    if (direction==1){
        // right
        isJumping=true;
        isFalling=false;
        if (moverRect.x+10 < 1100){
            moverRect.x+= 30;
        }
        
        facing=1;
        
    }
    if (direction==3){
        tobox=true;
        if( isJumping == true )
        {
            if( jump >= jumpHeight || isFalling == true )
            {
                jump--;
                if (jump==0)
                {
                    isFalling=false;
                    isJumping=false;
                }
                if (moverRect.y+30<=450)
                {
                    if (moverRect.x>1050 && moverRect.x<1400)
                    {
                        isFalling==true;
                    }
                    else
                    {
                        moverRect.y+=30;
                    }
                    isFalling = true;
                }
                if (moverRect.y+30>450)
                {
                    jump=0;
                }
                    

            }
            else if(( jump <= 0 && isFalling == true ))
            {
                    jump = 0;
                    isFalling = false;
                    isJumping = false;
            }
            else {
                    jump++;
                    //reach the box, go on top of the box
                    if (moverRect.x>=1050 && moverRect.x<1300){
                        moverRect.x+=30;
                        if (moverRect.x==1300){
                            isJumping=false;
                        }
                    }
                    moverRect.y-=30;
            }
        }
    }
}

//oop concept function overloading
void Person:: fly(int z){

    if (moverRect.x > 1100 && tobox==false){ 
        moverRect.x = 0; //starts from the beginning ,once it reaches the end
    }
    
    //srcRect deals with the coordinates of pigeon object from the assets file to help them move their wings

    if (z==1){
        //right key is being pressed
        if (animation == 0) { 
                srcRect = {2547,2976,916,853}; //Change to sprite 1
                animation =animation+ 1; //increment counter to move to next frame
            } else if (animation == 1) {
                srcRect = {1487,4086,441,816}; //Change to sprite 2
                animation=animation+ 1; //increment counter to move to next frame
            } 
            else if (animation==2){
                srcRect = {3005,4034,664,923}; //Change to sprite 3
                animation +=1; //reset to go back to first frame
            }
            else{
                animation=0;
                srcRect = {1487,4086,441,816};
            }
        }
    if (z==2){
        //left key is being pressed
        if (animation == 0) { 
                srcRect = {4057,3017,917,853}; //Change to sprite 1
                animation =animation+ 1; //increment counter to move to next frame
            } else if (animation == 1) {
                srcRect = {2327,4086,441,816}; //Change to sprite 2
                animation=animation+ 1; //increment counter to move to next frame
            } 
            else if (animation==2){
                srcRect = {3823,4075,663,922}; //Change to sprite 3
                animation +=1; //reset to go back to first frame
            }
            else {
                srcRect = {2327,4086,441,816}; //Change to sprite 3
                animation = 0; //reset to go back to first frame
            }
        }
}
void Person:: fly(int z, int o){

    if (moverRect.x > 1100 && tobox==false){ 
        moverRect.x = 0; //starts from the beginning ,once it reaches the end
    }
    

    if (z==1 || o==3){
        //right key is being pressed
        if (animation == 0) { 
                srcRect = {2547,2976,916,853}; //Change to sprite 1
                animation =animation+ 1; //increment counter to move to next frame
            } else if (animation == 1) {
                srcRect = {1487,4086,441,816}; //Change to sprite 2
                animation=animation+ 1; //increment counter to move to next frame
            } 
            else if (animation==2){
                srcRect = {3005,4034,664,923}; //Change to sprite 3
                animation +=1; //reset to go back to first frame
            }
            else{
                animation=0;
                srcRect = {1487,4086,441,816};
            }
        }
    if (z==2){
        //left key is being pressed
        if (animation == 0) {
                srcRect = {4057,3017,917,853}; //Change to sprite 1
                animation =animation+ 1; //increment counter to move to next frame
            } else if (animation == 1) {
                srcRect = {2327,4086,441,816}; //Change to sprite 2
                animation=animation+ 1; //increment counter to move to next frame
            } 
            else if (animation==2){
                srcRect = {3823,4075,663,922}; //Change to sprite 3
                animation +=1; //reset to go back to first frame
            }
            else {
                srcRect = {2327,4086,441,816}; //Change to sprite 3
                animation = 0; //reset to go back to first frame
            }
        }
}

// find the x and y coordinates of the Person to give to the knife
int Person::Person_X(){
    int xx;
    xx= moverRect.x;
    return xx;
}
int Person::Person_Y(){
    int yy;
    yy=moverRect.y;
    return yy;
}