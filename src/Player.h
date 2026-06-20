#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item.h"
#include "Skill.h"

using namespace std;

class Player {
private:
    string name;
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int attackPower;
    int gold;
    vector<Item> items;
    vector<Skill> skills;

public:
    Player();
    Player(string name, int hp, int mp, int attackPower);

    int attack();
    int useSkill(int index);
    void takeDamage(int damage);
    void useItem(int index);
    bool isAlive();

    void addItem(Item item);
    void addSkill(Skill skill);
    void showStatus();
    void showItems();
    void showSkills();
    void gainGold(int amount);

    string getName();
    int getHp();
    int getMp();
    int getAttackPower();
    int getGold();

    void setName(string name);
    void setHp(int hp);
    void setMp(int mp);
    void setAttackPower(int attackPower);
};

#endif
