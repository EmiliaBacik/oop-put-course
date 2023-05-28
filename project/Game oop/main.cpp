#include <iostream>
#include <time.h>
#include "Class.hpp"

using namespace std;

bool end_game=false;
int main()
{
    Player User;
    cout << endl << "Hi, " << User.CheckName() << "!" << endl;
    FireEnemy EasyE("Blaze", 1, 1, 1, 60);
    WaterEnemy EasyW("Wave", 2, 2, 1, 70);
    FireEnemy HardE("Lava", 4, 4, 5, 90);
    WaterEnemy HardW("Tsunami", 6, 5, 6, 100);
    while(end_game==false)
    {
        User.LevelUp();
        int tmp=0;
        cout << endl << "What do you want to do?" << endl << endl << "Enter 0 to exit the game." << endl<< "Enter 1 to check your statistics." << endl << "Enter 2 to heal yourself." << endl;
        cout << "Enter 3 to train." << endl << "Enter 4 to fight an easy fire enemy. " << endl << "Enter 5 to fight an easy water enemy.";
        cout << endl << "Enter 6 to fight a difficult fire enemy." << endl << "Enter 7 to fight a difficult water enemy." << endl;
         while(1)
        {
            try
            {
                cin >> tmp;
                if(tmp>=0 && tmp<=7)
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
        switch (tmp)
        {
        case 0:
            end_game = User.EndGame();
            break;
        case 1:
            User.CheckStats();
            break;
        case 2:
            User.HealYourself();
            break;
        case 3:
            User.TrainYourself();
            break;
        case 4:{
            if(User.CheckHp()!=0)
                {EasyE.Fight(User);}
            else
                cout << endl << "You have no HP!" << endl;
            break;}
        case 5:{
            if(User.CheckHp()!=0)
                {EasyW.Fight(User);}
            else
                cout << endl << "You have no HP!" << endl;
            break;}
        case 6:{
            if(User.CheckHp()!=0)
                {HardE.Fight(User);}
            else
                cout << endl << "You have no HP!" << endl;
            break;}
        case 7:{
            if(User.CheckHp()!=0)
                {HardW.Fight(User);}
            else
                cout << endl << "You have no HP!" << endl;
            break;}

        }
    }
    return 0;
}
