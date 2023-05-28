#include <iostream>
#include "Class.hpp"
using namespace std;

int Player::level=1;

void Player::CheckStats()
{
    cout << endl <<"Your stats: ";
    cout << endl << "Strong: " << stats[0];
    cout << endl << "Speed: " << stats[1];
    cout << endl << "Agility: " << stats[2];
    cout << endl << "Max hp: " << max_hp;
    cout << endl;
}

int Player::CheckHp()
{
    return hp;
}


string Player::CheckName()
{
    return login;
}

Player::Player()
{
    cout << "Enter your name: ";
    cin >> login;
    stats[0]=1;
    stats[1]=1;
    stats[2]=1;
    hp=65;
    max_hp=hp;
    exp=0;
    pet=false;
    cout << endl;

}

void Player::ImproveStats()
{
    cout << "Enter 1 to improve your strength, 2 to improve your speed or 3 to improve your agility." << endl;
    int tmp;
    while(1)
    {
        try
        {
            cin >> tmp;
            if (tmp==1 || tmp==2 || tmp==3)
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
    case 1:
        stats[0]++;
        cout << "You're stronger now!" << endl;
        break;
    case 2:
        stats[1]++;
        cout << "You're faster now!" << endl;
        break;
    case 3:
        stats[2]++;
        cout << "You're more agile now!" << endl;
        break;
    }

}


void Player::LevelUp()
{
    if(exp>=3)
    {
        level++;
        exp=0;
        max_hp+=15;
        cout << endl <<"Congratulations, you have leveled up! Now you have " << level << " level." << endl;
        cout << "You have obtained two stat points. You can choose which two stats you want to improve." << endl;
        ImproveStats();
        cout << "And the other point?" << endl;
        ImproveStats();
        CheckStats();
    }

}

void Player::HealYourself()
{
    cout << endl << "You rest for a few hours and regain all your strength";
    hp=max_hp;
    cout << endl << "Your HP now: " << hp <<endl;
}


bool Player::EndGame()
{
    cout << endl << endl << "Are you sure you want to leave the game? Your progress will not be saved." << endl << "Enter 1 to continue playing, enter 2 to exit: ";
    int tmp;
    while(1)
    {
        try
        {
            cin >> tmp;
            if (tmp==1 || tmp==2)
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
    case 1:
        cout << endl;
        return false;
        break;
    case 2:
        cout << endl << "Your progress: " << endl;
        CheckStats();
        cout << "Your level: " << level;
        cout << endl << "Your exp: " << exp;
        if(pet==true)
        {
            cout << endl << "You have a pet!";
        }
        cout << endl << endl << "Bye!";
        return true;
        break;
    }

}


void Player::TrainYourself()
{
    cout << endl << "You spend the whole day training!" << endl;
    exp++;
    ImproveStats();
}
