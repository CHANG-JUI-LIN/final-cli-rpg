#ifndef SKILL_H
#define SKILL_H

#include <string>

using namespace std;

class Skill {
private:
    // Skill name shown in the battle menu.
    string name;

    // Damage dealt when the skill is used.
    int damage;

    // MP required to cast this skill.
    int mpCost;

public:
    Skill();
    Skill(const string& name, int damage, int mpCost);

    // Use the skill and return its damage value.
    int use() const;

    // Print skill details for the player.
    void showInfo() const;

    int getDamage() const;
    string getName() const;
    int getMpCost() const;

    void setName(const string& name);
    void setDamage(int damage);
    void setMpCost(int mpCost);
};

#endif
