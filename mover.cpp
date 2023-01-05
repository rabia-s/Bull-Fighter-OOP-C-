// #include "mover.hpp"
// #include <iostream>
// #include "bee.hpp"

// // #include "seeplusia.hpp"

// const int xJump=200, yJump=160;
// // string gamteState= "running";

// // SDL_Rect bg={0,0,800,600};
// // SDL_Rect bgSrc={0,350,770,600};
// SDL_Rect warriorSrc={127,278,139,194};
// SDL_Rect warriorMover={50, 50, 50, 50};

// //Screen dimension constants
// const int SCREEN_WIDTH = 1000;
// const int SCREEN_HEIGHT = 500;


// void moveSouth(){ 
//     if (warriorMover.y+yJump < SCREEN_HEIGHT)warriorMover.y+=yJump;    
// }
// void moveNorth(){
// 	if (warriorMover.y-yJump > 0)warriorMover.y-=yJump;
// 	else warriorMover.y = 0;
// }
// void moveEast(){
// 	if (warriorMover.x+xJump < SCREEN_WIDTH)warriorMover.x+=xJump;
// }
// void moveWest(){
// 	if (warriorMover.x-xJump > 0)warriorMover.x-=xJump;
// }

// void moveWarrior(SDL_Renderer* gRenderer, SDL_Texture* dono_sath, SDL_Keycode key){
// 	Bees p1;
// 	// p1.fly();
//     if (key == SDLK_UP){
//         // makeMove("North");
// 		p1.fly();
// 		p1.move(4);
//     }
//     else if (key == SDLK_DOWN) {
//         // makeMove("South");
// 		p1.fly();
// 		p1.move(3);
//     }
//     else if (key == SDLK_RIGHT) {
//         // // makeMove("East");
// 		p1.fly();
// 		p1.move(2);
// 		moveEast();

// 		// if (warriorMover.x+xJump < SCREEN_WIDTH)warriorMover.x+=xJump;
//     }
//     else if (key == SDLK_LEFT) {
//         // // makeMove("West");
// 		p1.fly();
// 		p1.move(1);
// 		moveWest();
// 		// if (warriorMover.x-xJump > 0)warriorMover.x-=xJump;
//     }
//     else {
//         std::cout<<"hello";
//     }
//     update(gRenderer, dono_sath);
// }



// void update(SDL_Renderer* gRenderer, SDL_Texture* dono_sath){


// 	// SDL_RenderClear( gRenderer );
// 	// SDL_RenderCopy( gRenderer, dono_sath, &bgSrc, &bg );
// 	// status(gRenderer, dono_sath);
// 	SDL_RenderCopy( gRenderer, dono_sath, &warriorSrc, &warriorMover );
// 	SDL_RenderPresent( gRenderer );	
// 	SDL_Delay(5);	
// }