#ifndef SKILL_H
#define SKILL_h
#include<iostream>
#include<string>

class Skill
{
private:
    std::string name;
    int damage;
    int mpCost;
public:
    Skill();
    ~Skill();

    void use();
    void showInfo();
    int getDamage();
};




#endif