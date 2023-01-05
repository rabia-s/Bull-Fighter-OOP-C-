#include<SDL.h>
#include "bull.hpp"
#include "person.hpp"
#include "box.hpp"
#include "knife.hpp"


#include "knife2.hpp"
#include "bull_lives.hpp"
#include "person_lives.hpp"
#include "hit_person_boom.hpp"
#include "knife_hit_bull.hpp"
#include "life.hpp"
#include "gamewon.hpp"
#include "gamelost.hpp"
#pragma once
#include<vector>
#include<list>
#include <SDL_mixer.h>
using namespace std;

class BullFight{


    public:
    int p_lives=4, b_lives=4;
    int num_knives=6;
    int delete_knife=0;
    int temp_knife=6;
    bool remove_knife=false;
    bool finish=false;

    vector <Bull*>bulls;
    vector <Person*> persons; 
    vector <Box*> boxes; 
    vector <Knife*> knives1;
    vector <KnifeLeft*> knives2;
    list <Knife*> displayknives;
    list <Life*> lives; 
    
    Life object1;

    void reset(int);
    void drawObjects(); 
    void drawKnife(int);
    void createObject(int , int);
    void createKnife(int);
    void move(int);
    int check_collision();
    void begin_after_collide(int);
    // void createObject();
    ~BullFight();
};

