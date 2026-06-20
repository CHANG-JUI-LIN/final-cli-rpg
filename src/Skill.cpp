#include "Skill.h"

#include <algorithm>
#include <iostream>

using namespace std;

Skill::Skill() {
    name = "Basic Skill";
    damage = 10;
    mpCost = 5;
}

Skill::Skill(const string& name, int damage, int mpCost) {
    this->name = name;
    this->damage = max(0, damage);
    this->mpCost = max(0, mpCost);
}

int Skill::use() const {
    // The battle flow applies this returned damage to the monster.
    cout << "Used skill: " << name << endl;
    cout << "Skill damage: " << damage << endl;
    return damage;
}

void Skill::showInfo() const {
    cout << name
         << " | Damage: " << damage
         << " | MP Cost: " << mpCost
         << endl;
}

int Skill::getDamage() const {
    return damage;
}

string Skill::getName() const {
    return name;
}

int Skill::getMpCost() const {
    return mpCost;
}

void Skill::setName(const string& name) {
    this->name = name;
}

void Skill::setDamage(int damage) {
    this->damage = max(0, damage);
}

void Skill::setMpCost(int mpCost) {
    this->mpCost = max(0, mpCost);
}
