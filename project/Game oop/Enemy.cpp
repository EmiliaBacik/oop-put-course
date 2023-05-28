#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Class.hpp"
using namespace std;

int FireEnemy::magic = 1;
int WaterEnemy::magic = 2;



void Enemy::DrawStats(int strength_p=0, int speed_p=0, int agility_p=0, int hp_p=0)
{
    hp=hp_p;
    if(hp==0)
        hp=(int)(rand()%30)+40;
    strength=strength_p;
    if(strength==0)
        strength=(int)(rand()%20)+1;
    speed=speed_p;
    if(speed==0)
        speed=(int)(rand()%20)+1;
    agility=agility_p;
    if(agility==0)
        agility=(int)(rand()%20)+1;

}

FireEnemy::FireEnemy(string name_p, int strength_p=0, int speed_p=0, int agility_p=0, int hp_p=0)
{
    name=name_p;
    DrawStats(strength_p, speed_p, agility_p, hp_p);

}

WaterEnemy::WaterEnemy(string name_p, int strength_p=0, int speed_p=0, int agility_p=0, int hp_p=0)
{
    name=name_p;
    DrawStats(strength_p, speed_p, agility_p, hp_p);

}




void FireEnemy::CheckStats()
{
    cout << endl << "Name: " << name;
    cout << endl << "Strength: " << strength;
    cout << endl << "Speed: " << speed;
    cout << endl << "Agility: " << agility;
    cout << endl << "HP: " << hp;
    cout << endl << "Magic: " << (magic==1 ? "Fire" : (magic==2 ? "Water" : (magic==3 ? "Earth" : "Air")));
    cout << endl;
}
