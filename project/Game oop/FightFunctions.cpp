#include <iostream>
#include <time.h>
#include "FightFunctions.hpp"
using namespace std;

int WhoStarts()
{
    srand(time(NULL));
    int x=rand()%2;
    return x;
}
int ChooseAction()
{
    cout << endl << "Your turn. Enter 1 to attack, 2 to defend yourself and 3 to run away: ";
    int tmp;
    while(1)
    {
        try
        {
            cin >> tmp;
            if(tmp==1 || tmp==2 || tmp==3)
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
    return tmp;
}

int Attack(int attacker_stats[3], int defence_stats[3], bool defence)
{
    srand(time(NULL));
    int hp = 0;
    if(defence)
        hp=(3*attacker_stats[0]*2*attacker_stats[1]) - (3*defence_stats[2]*2*defence_stats[1]);
    else
        hp=(3*attacker_stats[0]*2*attacker_stats[1]) - (1*defence_stats[2]*1*defence_stats[1]);
    hp=hp*2;
    hp = hp +(rand()%6)-3;
    if(hp<=0)
       {
           hp=0;
       }
    return hp;
}

bool RunAway(int user, int enemy)
{
    if(user+1>=enemy)
    {
        cout << endl << "You managed to escape!" << endl;
        return true;
    }
    else
        cout << endl << "You failed to escape!";
        return false;
}

bool Tame(string name)
{
    cout << endl << name << " asks you a riddle... " << endl << "A box without hinges, key, or lid," << endl << "Yet golden treasure inside is hid." << endl;
    cout << endl << "If you think it's geode enter 1, if you think ,,maybe eggs'' - enter 2, if you want to guess it's the core of the Earth - enter 3: ";
    int tmp;
    while(1)
    {
        try
        {
            cin >> tmp;
            if(tmp==1 || tmp==2 || tmp==3)
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
    if(tmp==2)
        return true;
    else
    {
        cout << endl << "Unfortunately, it's not the correct answer. " << name << " runs away, and you stay alone.";
        return false;
    }
}
