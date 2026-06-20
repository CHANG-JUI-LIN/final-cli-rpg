#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster() {
    name = "Slime";
    hp = 50;
    attackPower = 10;
    rewardGold = 10;
}

Monster::Monster(string name, int hp, int attackPower, int rewardGold) {
    this->name = name;
    this->hp = hp;
    this->attackPower = attackPower;
    this->rewardGold = rewardGold;
}

int Monster::attack() {
    cout << name << " attacks!" << endl;
    cout << "Damage: " << attackPower << endl;
    return attackPower;
}

void Monster::takeDamage(int damage) {
    hp -= damage;

    if (hp < 0) {
        hp = 0;
    }

    cout << name << " took " << damage << " damage." << endl;
}

bool Monster::isAlive() {
    return hp > 0;
}

void Monster::showInfo() {
    cout << endl;
    cout << "----- Monster Info -----" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << endl;
    cout << "Attack: " << attackPower << endl;
    cout << "Reward Gold: " << rewardGold << endl;
    cout << "------------------------" << endl;
}

string Monster::getName() {
    return name;
}

int Monster::getHp() {
    return hp;
}

int Monster::getAttackPower() {
    return attackPower;
}

int Monster::getRewardGold() {
    return rewardGold;
}

void Monster::setName(string name) {
    this->name = name;
}

void Monster::setHp(int hp) {
    this->hp = hp;
}

void Monster::setAttackPower(int attackPower) {
    this->attackPower = attackPower;
}

void Monster::setRewardGold(int rewardGold) {
    this->rewardGold = rewardGold;
}
