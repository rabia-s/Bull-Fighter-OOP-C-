#include "game.hpp"
#include "BullFight.hpp"
#include "drawing.hpp"



SDL_Renderer* Drawing::gRenderer = NULL;
// SDL_Renderer* Drawing::gRenderer2 = NULL;
SDL_Texture* Drawing::assets = NULL;
// SDL_Texture* Drawing::assets2 = NULL;
// SDL_Texture* Drawing::assets3 = NULL;

bool Game::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "HU Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2300) < 0 )
    	{
			printf( "Unable to open audio: %s\n", Mix_GetError());
			success=false;
    	}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				// SDL_SetRenderDrawColor( Drawing::gRenderer2, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	music=Mix_LoadMUS("bgmusic.mp3");
	Mix_PlayMusic(music, 0);
	Drawing::assets = loadTexture("assets_finalfinal.png");
    gTexture = loadTexture("home_screen.PNG");
	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	if( music == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
	return success;
}

void Game::close()
{
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
bool state = false;
bool check=false, quit=false, instruct=false;
void Game::run()
//const vector<int> &vect 
{	
	SDL_Event e;
	SDL_Event e2;
	
	// condition only call objects once hence the bool 
	// bool state = false;
	bool quit = false;
	bool knife= false;	


	BullFight bullfight;
	// bullfight.createObject(0, 0);
	while( !quit )
	{
		
		SDL_RenderClear(Drawing::gRenderer); 
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);
		
	if (screengame==false){
		while (SDL_PollEvent(&e2) != 0){
			if (e2.type== SDL_QUIT){
				quit=true;
			}
			if (screeninstruct==true && e2.type==SDL_KEYDOWN){
				gTexture= loadTexture("capture.png");
				screeninstruct=false;
				screengame=true;
				}
			if (e2.type== SDL_MOUSEBUTTONDOWN){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				
				if (xMouse>585 && xMouse< 827 && yMouse > 302 && yMouse< 370 && screenhome==true){
					instruct=true;
					gTexture= loadTexture("capture.png");
					screenhome=false;
					screeninstruct=false;
					screengame=true;
					check=true;
				}
				if (xMouse>488 && xMouse< 943 && yMouse > 390 && yMouse< 472 && screenhome==true){
					instruct=true;
					gTexture= loadTexture("instructions.png");
					screenhome=false;
					screeninstruct=true;
					screengame=false;
					check=true;
				}
				
			}
		}
	}

		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 && screengame==true)
		{
			
			
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			

			if (state==false){
				bullfight.createObject(0, 0);
				state=true;
			}

			//if conditions will detect which key is being pressed and will do functions accordingly
			if (state==true and e.type== SDL_KEYDOWN){
			// bullfight.check_collision();
				//right 1, left 2, up 3 for moving the banda
				if (e.key.keysym.sym== SDLK_RIGHT){
					bullfight.move(1);
				}
				if (e.key.keysym.sym== SDLK_LEFT){
					bullfight.move(2);
				}
				if (e.key.keysym.sym== SDLK_UP){
					bullfight.move(3);
				}
				
				//person can generate knife by pressing key "A" OR "D"
				if (e.key.keysym.sym== SDLK_d){
					music=Mix_LoadMUS("knife.mp3");
					bullfight.createKnife(1);
					knife_type=1;
					bullfight.move(4);
					knife= true;
				}
				if (e.key.keysym.sym== SDLK_a){
					music=Mix_LoadMUS("knife.mp3");
					bullfight.createKnife(2);
					knife_type=2;
					bullfight.move(4);
					knife= true;
				}

			}
			
		}
		
		
		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer

		//***********************draw the objects here********************
		
		bullfight.drawObjects();
		bullfight.drawKnife(knife_type);
		int draw_again;
		if (state==true)
		{
			draw_again=bullfight.check_collision();
			if (draw_again==1)
			{
				// music=Mix_LoadMUS("knife.mp3");
				// Mix_PlayMusic(music, 0);
				bullfight.begin_after_collide(0);
			}
		}

		knife=false;

		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer
		// SDL_RenderPresent(Drawing::gRenderer2); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}
