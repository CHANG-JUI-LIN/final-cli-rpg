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
    // A skill only reports its damage. The battle flow applies this value to the monster.
    cout << "Used skill: " << name << endl;
    cout << "Skill damage: " << damage << endl;
    return damage;
}

void Skill::showInfo() const {
    // Display the information needed when the player chooses a skill.
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
    // Damage should not be negative in the battle system.
    this->damage = max(0, damage);
}

void Skill::setMpCost(int mpCost) {
    // MP cost should not be negative.
    this->mpCost = max(0, mpCost);
}
