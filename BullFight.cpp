
#include <iostream>
#include "BullFight.hpp"
#pragma once
using namespace std;
#include <iostream>
#include <typeinfo>

bool call_bull= false;
//implemented factory design on the parent class life and child classes bullLife and personLife
class Factorylives{
    public:
    Factorylives(){};
    Life*  getObject(int x, int object){

        if (object==1){
            Life* obj1= new bullLives(x, 20);
            return obj1;
        }
        if (object==2){
            Life* obj1= new personLives(x, 20);
            return obj1;
        } 
    }
};

//once objects have been created, they will be drawn and shown on the screen
void BullFight::drawObjects()
{
    int i= 0,j=0,k=0;
    while ( j < boxes.size()){
        boxes[j]->draw();       
        j++;
    }   
    while (i < bulls.size()){ 
        bulls[i]->draw(); 
        bulls[i]->fly();   
        i++;  
    }
    while ( k < persons.size()){
        persons[k]->draw();        
        k++;
    }
    i=0;
    for (Life* l: lives){
        l-> draw();
    }
    for (Knife*kn: displayknives){
        kn->draw();
    }
}

//create objects upon game start 
void BullFight::createObject(int x, int y)
{   

    Bull* P=new Bull(0, 450);
    bulls.push_back(P);

    Person *B=new Person(500, 450);//create user in the center of the screen
    persons.push_back(B);

    Box *X=new Box(1200, 450);//create box at the left corner of the screen
    boxes.push_back(X);

    //display the lives of bull and person on top of the screen
    Factorylives O;
    int heart_x=300;
    for (int i=0; i< 4; i++){
        Life *obj = O.getObject(heart_x, 1);
        lives.push_back(obj);
        heart_x+=50;
    }
    heart_x=1000;
    for (int i=0; i< 4; i++){
        Life *obj = O.getObject(heart_x, 2);
        lives.push_back(obj);
        heart_x-=50;
    }

    //display knives at the top of the screen
    int knife_x=50;
    for (int i=0; i<6; i++){
        Knife*k2 = new Knife(knife_x, 100);
        displayknives.push_back(k2);
        knife_x+=100;
    }


}

//call this function when a collision has taken place to start from the initail positions
void BullFight::begin_after_collide(int condition)
{    
    if (condition==1){
        //person has lost the game and display GameLost
        bulls.clear();
        persons.clear();
        knives1.clear();
        knives2.clear();
        // while (knives1.empty()==false)
        // {
        //     auto it=knives1.begin();  //destructing pigeons
        //     knives1.erase(it);
        // } 
        GameLost* g= new GameLost(450, 150);
        g-> draw();
        finish=true;
    }
    else{
        //restart the game normally without displaying GameLost
        bulls.clear();
        persons.clear();
        knives1.clear();
        knives2.clear();
        Bull* P=new Bull(0, 450);
        bulls.push_back(P);

        Person *B=new Person(500, 450);
        persons.push_back(B);

        int i=0, k=0;
        while (i < bulls.size()){ 
            bulls[i]->restart();
            bulls[i]->draw(); 
            bulls[i]->fly();   
            i++;  
        }
        while ( k < persons.size()){
            persons[k]->draw();        
            k++;
        }
    }
}

bool knife_create=false;

//create knife1 or knife2 depending on what key the user has pressed
void BullFight:: createKnife(int type){
    int brox, broy;
    remove_knife=true;
    brox=persons[0]->Person_X();
    broy=persons[0]->Person_Y();
    //type is the knife type
    if (type==1)
    {
        Knife *K=new Knife(brox, broy+50);//create knife at the same y coordinate as the Person
        knives1.push_back(K);
    }
    if (type==2)
    {
        KnifeLeft *K2= new KnifeLeft(brox, broy+50);
        knives2.push_back(K2);
    }
    knife_create=true;
}
Life object1;

//call this function when the game is lost and needs to delete things
void BullFight:: reset(int f)
{
    if (f==1){
        bulls.clear();
        persons.clear();
        knives1.clear();
        knives2.clear();
        GameLost* g= new GameLost(450, 150);
        g-> draw();
        finish=true;
    }
    else{
        bulls.clear();
        persons.clear();
        knives1.clear();
        knives2.clear();
        GameWon* g= new GameWon(450, 150);
        g-> draw();
        finish=true;
    }
    
}

//make objects for each knife class
Knife k1;
KnifeLeft k2;


void BullFight::drawKnife(int type)
{
    //if both knifes =0, restart the game
    if (k1.num_knife==0 && k2.num_knife==0)
    {
        begin_after_collide(1);
    }

    //the knifes have not finished yet, continue the game normally
    else{
        //only generate knives if the number of knives have not finished yet
        if (type==1 && k1.num_knife!=0){
            int i=0;
            knives1[i]->draw(); 
            knives1[i]->move();
            
            if (remove_knife==true )
            {
                displayknives.remove(displayknives.back()); 
                remove_knife=false;
                //operator overloading implemented for knife
                -k1;
            }
            
            i++;  
            
        }
        if (type==2 && k2.num_knife!=0)
        {
            int i=0;
            knives2[i]->draw(); 
            knives2[i]->move(); 
            if (remove_knife==true)
            {
                displayknives.remove(displayknives.back()); 
                remove_knife=false;
                -k2;
            }
            i++;  
        }
    }
}

int BullFight:: check_collision()
{
    //compare the x and y coordinates and check for collision
    int person_x, person_y, bull_x, bull_y, knife_x, knife_y;
    person_x=persons[0]->Person_X();
    person_y=persons[0]->Person_Y();
    bull_x=bulls[0]->get_bull_x();
    bull_y=bulls[0]->get_bull_y();
    

    //if condition checks if the bull has hit the person
    int range= abs(person_x-bull_x);
    if (range<=100 && person_y==bull_y ){
        for (Life* l: lives)
        {
            //operator overload for life       
            -object1;
            if (p_lives-1==0){
                lives.remove(lives.back());
                begin_after_collide(1);
                reset(1);
            }
            else{
                p_lives-=1;
            
                lives.remove(lives.back());
                Boom *boom = new Boom(person_x, bull_y);
                boom->draw();
                return 1;
                break;
            }
        }    
    }
    //if condition to check if the knife1 hits bull
    if (knives1.size()!=0){
    knife_x=knives1[0]-> get_knife_x();
    knife_y=knives1[0]-> get_knife_y();
    int range= abs(knife_x-bull_x);

    if (range<=20){
        for (Life* l: lives){
        -object1;
            if (b_lives-1==0){
                lives.remove(l);
                begin_after_collide(1);
                reset(2);
            }
            else{
                b_lives-=1;
            
                lives.remove(l);
                Boom *boom = new Boom(knife_x, bull_y);
                boom->draw();
                return 1;
                break;
            }
        }    
    }
    }

    //check if knife2 has hit the bull
    if (knives2.size()!=0){
    knife_x=knives2[0]-> get_knife_x();
    knife_y=knives2[0]-> get_knife_y();
    int range= abs(knife_x-bull_x);

    if (range<=20){
        for (Life* l: lives)
        {
            -object1;
            if (b_lives-1==0)
            {
                lives.remove(l);
                reset(2);
            }
            else{
                b_lives-=1;
            
                lives.remove(l);
                Boom *boom = new Boom(knife_x, bull_y);
                boom->draw();
                return 1;
                break;
            }
        }    
    }
    }

}

//function overloading for fly() implemented below for the person class
void BullFight:: move(int x)
{
    
    persons[0]->move(x);
    if (x==3){
        persons[0]->fly(1, x);
    }
    else{
        persons[0]->fly(x);
    }
}

BullFight :: ~BullFight(){
    for(Life *u: lives){ //dynamically deletes list objs inside our Unit through destructor
        delete u;
    cout<<"destruct"<<endl;
    }
    lives.clear();
    while (bulls.empty()==false){
        auto it=bulls.begin();  //destructing bulls
        bulls.erase(it);
        //cout<<"delete"<<endl;
    } 

    while (persons.empty()==false){
        auto it2=persons.begin();  ////destructing person
        persons.erase(it2);
    } 

    while (boxes.empty()==false){
        auto it3=boxes.begin();  ////destructing box
        boxes.erase(it3);
    }  

    while (knives1.empty()==false){
        auto it4=knives1.begin();  ////destructing knife1
        knives1.erase(it4);
    }      

    while (knives2.empty()==false){
        auto it5=knives2.begin();  ////destructing knife2
        knives2.erase(it5);
    } 
    
}
// int BullFight:: check_collision(){
//     int person_x, person_y, bull_x, bull_y, knife_x, knife_y;
//     person_x=persons[0]->Person_X();
//     person_y=persons[0]->Person_Y();
//     bull_x=bulls[0]->get_bull_x();
//     bull_y=bulls[0]->get_bull_y();
    
    
//     //if condition checks if the bull has hit the person
//     int range= abs(person_x-bull_x);
//     if (range<=100 && person_y==bull_y && finish==false){
//         bool cond=true;
//         for (Life* l: lives){ 
//             int i= l->get_identity();
//             std::cout << "I IS "<< i<< std::endl;
//             if (i==1&& cond==true){
//             std::cout << "identity for working p "<< i<< std::endl;
//             -object1;
//             cond=false;
//             lives.remove(lives.back());
//             if (object1.number_lives==0){
//                 begin_after_collide(1);
//                 finish=true;
//                 break;
//             }
//             if (cond==false){break;}
            
//         }
//             // -object1;
//             // lives.remove(lives.back());
//             // if (object1.number_lives==0){
//             //     begin_after_collide(1);
//             //     finish=true;
//             //     break;
//             // }
//             else{
//                 Boom *boom = new Boom(person_x, bull_y);
//                 boom->draw();
//                 return 1;
//                 break;
//             }
//         }    
//     }

//     if (knives1.size()!=0 && finish==false){
//     knife_x=knives1[0]-> get_knife_x();
//     knife_y=knives1[0]-> get_knife_y();
//     int range= abs(knife_x-bull_x);
//     int rnage2;

//         if (range<=20 ){
//             for (Life* l: lives){
//             // l-> update_lives();
//             int i= l->get_identity();
//             if (i==1){
//             std::cout << "identity for working bull "<< i<< std::endl;
//             -object1;
//             lives.remove(l);
//             if (object1.number_lives==0){
//                 begin_after_collide(1);
//                 finish=true;
//                 break;
//             }
//         }
//             // -object1;
//             // lives.remove(l);
//             // if (object1.number_lives==0){
//             //     begin_after_collide(1);
//             //     finish=true;
//             //     break;
//             // }
//             // lives.remove(l);
//             // displayknives.remove(displayknives.back()); 
//             Boom *boom = new Boom(knife_x, bull_y);
//             boom->draw();
//             return 1;
//             break;
//             }    
//         }
//     }
//     if (knives2.size()!=0 && finish==false){
//     knife_x=knives2[0]-> get_knife_x();
//     knife_y=knives2[0]-> get_knife_y();
//     int range= abs(knife_x-bull_x);

//     if (range<=20 && finish==false){
//         for (Life* l: lives){
//         // l-> update_lives();
//         int i= l->get_identity();
//         if (i==1){
//             std::cout << "identity for working bull "<< i<< std::endl;
//             -object1;
//             lives.remove(l);
//             if (object1.number_lives==0){
//                 begin_after_collide(1);
//                 finish=true;
//                 break;
//             }
//         }
        
//         //lives.remove(l);
//         // displayknives.remove(displayknives.back()); 
         
//         Boom *boom = new Boom(knife_x, bull_y);
//         boom->draw();
//         return 1;
//         break;
//         }    
//     }
//     }

// }