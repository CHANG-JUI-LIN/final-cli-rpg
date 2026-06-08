#ifndef MONSTER_H
#define MONSTER_H

#include<iostream>
#include<string>

class Monster
{
private:
    std::string name;
    int hp;
    int attackPower;
    int rewardGold;

public:
    Monster(/* args */);
    ~Monster();

    int attack();
    int takeDamage();
    bool isAlive();
    void showInfo();
};




#endif