#ifndef FightFunctions_hpp
#define FightFunctions_hpp
#include <iostream>

int WhoStarts();
int ChooseAction();
int Attack(int attacker_stats[3], int defence_stats[3], bool defence);
bool RunAway(int user, int enemy);
bool Tame(std::string name);
#endif
