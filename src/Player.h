#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

class Player
{
private:
    std::string name;
    int hp;
    int maxHp;
    int attackPower;
    std::vector<std::string> items;
public:
    Player();
    ~Player();

    int attack() const;
    void takeDamage(int damage);
    void useItem();
    bool isAlive() const;

    std::string getName() const;
    int getHp() const;
    int getAttackPower() const;
};




#endif
