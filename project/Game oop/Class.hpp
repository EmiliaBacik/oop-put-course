#ifndef Class_hpp
#define Class_hpp
#include <iostream>

using namespace std;

class Player;

class Enemy
{
protected:
    int strength;
    int speed;
    int agility;
    int hp;
public:
    Enemy() = default;
    virtual ~Enemy() = default;
    virtual void Fight(Player &)=0;
    virtual void DrawStats(int strength_p, int speed_p, int agility_p, int hp_p);
};

class FireEnemy :public Enemy
{
private:
    string name;
    static int magic;
public:
    FireEnemy(string name_p, int strength_p, int speed_p, int agility_p, int hp_p);
    ~FireEnemy() = default;
    void CheckStats();
    virtual void Fight(Player &) override;
};

class WaterEnemy :public Enemy
{
private:
    string name;
    static int magic;
public:
    WaterEnemy(string name_p, int strength_p, int speed_p, int agility_p, int hp_p);
    ~WaterEnemy() = default;
    virtual void Fight(Player &) override;
};



class Player
{
    friend void Enemy::Fight(Player &);
    friend void FireEnemy::Fight(Player &);
    friend void WaterEnemy::Fight(Player &);
private:
    string login;
    int stats[3]; // 0-strength 1-speed 2-agility
    int hp;
    int max_hp;
    int exp;
    static int level;
    bool pet;
    void ImproveStats();
public:
    Player();
    ~Player() = default;
    void CheckStats();
    int CheckHp();
    string CheckName();
    void LevelUp();
    void HealYourself();
    void TrainYourself();
    bool EndGame();
};

#endif
