#include "Monster.h"

#include <algorithm>
#include <iostream>

using namespace std;

Monster::Monster() {
    name = "Slime";
    hp = 50;
    attackPower = 10;
    rewardGold = 10;
}

Monster::Monster(const string& name, int hp, int attackPower, int rewardGold) {
    this->name = name;
    this->hp = max(0, hp);
    this->attackPower = max(0, attackPower);
    this->rewardGold = max(0, rewardGold);
}

int Monster::attack() const {
    cout << name << " attacks!" << endl;
    cout << "Damage: " << attackPower << endl;
    return attackPower;
}

void Monster::takeDamage(int damage) {
    hp = max(0, hp - max(0, damage));
    cout << name << " took " << damage << " damage." << endl;
}

bool Monster::isAlive() const {
    return hp > 0;
}

void Monster::showInfo() const {
    cout << endl;
    cout << "----- Monster Info -----" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << endl;
    cout << "Attack: " << attackPower << endl;
    cout << "Reward Gold: " << rewardGold << endl;
    cout << "------------------------" << endl;
}

string Monster::getName() const {
    return name;
}

int Monster::getHp() const {
    return hp;
}

int Monster::getAttackPower() const {
    return attackPower;
}

int Monster::getRewardGold() const {
    return rewardGold;
}

void Monster::setName(const string& name) {
    this->name = name;
}

void Monster::setHp(int hp) {
    this->hp = max(0, hp);
}

void Monster::setAttackPower(int attackPower) {
    this->attackPower = max(0, attackPower);
}

void Monster::setRewardGold(int rewardGold) {
    this->rewardGold = max(0, rewardGold);
}
