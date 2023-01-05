
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>



class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1400;
    const int SCREEN_HEIGHT = 650;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;

    Mix_Music* music=NULL;
    

public:


    int knife_state;
    int knife_type;
    bool init();
    bool loadMedia();
    void close();
    
    bool screenhome=true, screeninstruct=false, screengame=false;
    SDL_Texture* loadTexture( std::string path );

    // trying to pass vector by reference  const vector<int> &vect
    void run();
};
