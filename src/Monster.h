#ifndef MONSTER_H
#define MONSTER_H

#include <string>

using namespace std;

class Monster {
private:
    string name;
    int hp;
    int attackPower;
    int rewardGold;

public:
    Monster();
    Monster(string name, int hp, int attackPower, int rewardGold);

    int attack();
    void takeDamage(int damage);
    bool isAlive();
    void showInfo();

    string getName();
    int getHp();
    int getAttackPower();
    int getRewardGold();

    void setName(string name);
    void setHp(int hp);
    void setAttackPower(int attackPower);
    void setRewardGold(int rewardGold);
};

#endif
