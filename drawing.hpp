#include<SDL.h>
#pragma once
class Drawing{
    public:
        //The window renderer
    static SDL_Renderer* gRenderer;
    static SDL_Renderer* gRenderer2;
    //global reference to png image sheets
    static SDL_Texture* assets;
    static SDL_Texture* assets2;
    static SDL_Texture* assets3;
};