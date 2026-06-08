#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>

class Player
{
private:
    std::string name;
    int hp;
    int attackPower;
    std::string items[];
public:
    Player();
    ~Player();

    int attack();
    int takeDamage();
    void useItem();
    bool isAlive();
};




#endif PLAYER_H