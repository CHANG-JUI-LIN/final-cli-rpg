#include "Skill.h"
#include <iostream>

using namespace std;

Skill::Skill() {
    name = "Basic Skill";
    damage = 10;
    mpCost = 5;
}

Skill::Skill(string name, int damage, int mpCost) {
    this->name = name;
    this->damage = damage;
    this->mpCost = mpCost;
}

int Skill::use() {
    cout << "Used skill: " << name << endl;
    cout << "Skill damage: " << damage << endl;
    return damage;
}

void Skill::showInfo() {
    cout << name
         << " | Damage: " << damage
         << " | MP Cost: " << mpCost
         << endl;
}

int Skill::getDamage() {
    return damage;
}

string Skill::getName() {
    return name;
}

int Skill::getMpCost() {
    return mpCost;
}

void Skill::setName(string name) {
    this->name = name;
}

void Skill::setDamage(int damage) {
    this->damage = damage;
}

void Skill::setMpCost(int mpCost) {
    this->mpCost = mpCost;
}
