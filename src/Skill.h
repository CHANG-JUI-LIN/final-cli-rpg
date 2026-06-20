#ifndef SKILL_H
#define SKILL_H

#include <string>

using namespace std;

class Skill {
private:
    string name;
    int damage;
    int mpCost;

public:
    Skill();
    Skill(string name, int damage, int mpCost);

    int use();
    void showInfo();
    int getDamage();

    string getName();
    int getMpCost();

    void setName(string name);
    void setDamage(int damage);
    void setMpCost(int mpCost);
};

#endif
