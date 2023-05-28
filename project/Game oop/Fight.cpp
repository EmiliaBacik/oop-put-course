#include <iostream>
#include <time.h>
#include "Class.hpp"
#include "FightFunctions.hpp"
using namespace std;

// 0-strength 1-speed 2-agility


void FireEnemy::Fight(Player &p)
{
    int stats[3]={strength, speed, agility};
    //cout << endl << "Enemystat's: Strenght - " << stats[0] << " Speed - " << stats[1] << " Agility - " << stats[2];
    int x = 0, y=0;
    int enemy_max_hp=hp;
    bool enemy_defence=false, user_defence=false;
    cout << endl << endl << "A fight between you and " << name << " has begun!";
    cout << endl << "Be careful, fire enemies' hits are strong!";

    int turn = WhoStarts();
    while(p.hp>0 && hp>0)
    {
    cout << endl << "Your HP: " << p.hp << "    Enemy's HP: " << hp << endl;
        if (turn==0)
        {
            x = ChooseAction();
            switch (x)
            {
            case 1:{
                int power_of_attack = Attack(p.stats, stats, enemy_defence);
                hp = hp - power_of_attack;
                cout << p.login << " deals " << power_of_attack << " damage!";
                user_defence=false;
                break;}
            case 2: {
                user_defence=true;
                if(p.hp<=p.max_hp-2)
                    p.hp=p.hp+2;
                cout << p.login << " defends itself and regenerates 2 points of HP.";
                break;}
            case 3:{
                if(p.hp<=p.max_hp-2)
                    p.hp=p.hp+2;
                if(RunAway(p.stats[1], stats[1])==true)
                {
                    p.hp=p.max_hp;
                    if(p.hp<0)
                        p.hp=0;
                    return;
                }
                break;}
            }
            turn=1;
        }
        else if(turn==1)
        {
            if(hp<20)
                y=2;
            else if(rand()%5==0)
                y=2;
            else
                y=1;
            switch (y)
            {
            case 1:{
                int power_of_attack2 = Attack(stats, p.stats, user_defence);
                p.hp= p.hp - power_of_attack2;
                cout << endl << name << " deals " << power_of_attack2 << " damage!";
                enemy_defence=false;
                break;}
            case 2:{
                enemy_defence=true;
                cout << endl << name << " defends itself.";
                break;}
            }
            turn=0;
        }
    }
    if(p.hp<=0)
    {
        cout << endl << endl << "You lost! You have to heal yourself before you can fight again..." << endl;
        hp=enemy_max_hp;
        if(p.hp<0)
            p.hp=0;
        return;
    }
    else
    {
        cout << endl << endl << "Victory! Congratulations, you can now increase your stats by one point." << endl << "You obtained an experience point. ";
        p.exp++;
        p.ImproveStats();
        cout << endl;
        hp=enemy_max_hp;
        if(p.hp<0)
            p.hp=0;
        return;
    }
}


void WaterEnemy::Fight(Player &p)
{
    int stats[3]={strength, speed, agility};
    //cout << endl << "Enemystat's: Strength - " << stats[0] << " Speed - " << stats[1] << " Agility - " << stats[2];
    int x = 0, y=0;
    int enemy_max_hp=hp;
    bool enemy_defence=false, user_defence=false, tame=false;
    cout << endl << endl << "You encounter " << name << "!";
    cout << endl << "You can tame it when its HP falls to 20!";

    int turn = WhoStarts();
    while(p.hp>0 && hp>0 && tame==false)
    {
    cout << endl << "Your HP: " << p.hp << "    Enemy's HP: " << hp << endl;
        if (turn==0)
        {
            x = ChooseAction();
            switch (x)
            {
            case 1:{
                int power_of_attack = Attack(p.stats, stats, enemy_defence);
                hp = hp - power_of_attack;
                cout << p.login << " deals " << power_of_attack << " damage!";
                user_defence=false;
                break;}
            case 2: {
                user_defence=true;
                if(p.hp<=p.max_hp-5)
                    p.hp=p.hp+5;
                cout << p.login << " defends itself.";
                break;}
            case 3:{
                if(p.hp<=p.max_hp-5)
                    p.hp=p.hp+5;
                if(RunAway(p.stats[1], stats[1])==true)
                {
                    p.hp=p.max_hp;
                    if(p.hp<0)
                        p.hp=0;
                    return;
                }
                break;}
            }
            turn=1;
        }
        else if(turn==1)
        {
            if(hp<=20)
                y=3;
            else if(rand()%5==0)
                y=2;
            else
                y=1;
            switch (y)
            {
            case 1:{
                int power_of_attack2 = Attack(stats, p.stats, user_defence);
                p.hp= p.hp - power_of_attack2;
                cout << endl << name << " deals " << power_of_attack2 << " damage!";
                enemy_defence=false;
                break;}
            case 2:{
                enemy_defence=true;
                cout << endl << name << " defends itself.";
                break;}
            case 3:
                tame=true;
            }
            turn=0;
        }
    }
    if(p.hp<=0)
    {
        cout << endl << endl << "You lost! You have to heal yourself before you can fight again..." << endl;
        return;
    }
        cout << endl << endl << "This is a good moment to try to tame it!" << endl << "Enter 1 if you want to try or 2 if you want to win this duel: ";
        int tmp;
        while(1)
        {
            try
            {
                cin >> tmp;
                if(tmp==1 || tmp==2)
                    break;
                else
                throw invalid_argument("error");
            }
            catch(invalid_argument)
            {
                cout << "Try again!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }
        if(tmp==1)
        {
          bool have_pet = Tame(name);
          if(have_pet==true)
          {
              cout << endl << "Success! You have a pet now! It goes home to rest a little... You will be able to play with it in a few hours." << endl;
              p.pet=true;
              p.exp++;
              p.exp++;
              p.ImproveStats();
              hp=enemy_max_hp;
              if(p.hp<0)
                p.hp=0;
              return;
          }
          hp=enemy_max_hp;
          if(p.hp<0)
            p.hp=0;
          return;
        }
        else
        {
            cout << endl << endl << "Victory! Congratulations, you can now increase your stats by one point." << endl << "You obtained an experience point. ";
            p.exp++;
            p.ImproveStats();
        }
        cout << endl;
        hp=enemy_max_hp;
        if(p.hp<0)
            p.hp=0;
        return;
}
