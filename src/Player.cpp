#include "Player.h"

#include <algorithm>
#include <iostream>

using namespace std;

Player::Player() {
    name = "Hero";
    hp = 100;
    maxHp = 100;
    mp = 30;
    maxMp = 30;
    attackPower = 15;
    gold = 0;
}

Player::Player(const string& name, int hp, int mp, int attackPower) {
    this->name = name;
    this->hp = max(1, hp);
    this->maxHp = this->hp;
    this->mp = max(0, mp);
    this->maxMp = this->mp;
    this->attackPower = max(0, attackPower);
    this->gold = 0;
}

int Player::attack() const {
    cout << name << " uses normal attack!" << endl;
    cout << "Damage: " << attackPower << endl;
    return attackPower;
}

int Player::useSkill(int index) {
    if (index < 0 || index >= static_cast<int>(skills.size())) {
        cout << "Invalid skill number." << endl;
        return 0;
    }

    const Skill& skill = skills[index];
    if (mp < skill.getMpCost()) {
        cout << "Not enough MP!" << endl;
        return 0;
    }

    mp -= skill.getMpCost();
    return skill.use();
}

void Player::takeDamage(int damage) {
    hp = max(0, hp - max(0, damage));
    cout << name << " took " << damage << " damage." << endl;
}

void Player::useItem(int index) {
    if (index < 0 || index >= static_cast<int>(items.size())) {
        cout << "Invalid item number." << endl;
        return;
    }

    Item& item = items[index];
    if (!item.isAvailable()) {
        cout << "This item is not available." << endl;
        return;
    }

    int value = item.use();
    if (item.getType() == "heal") {
        hp = min(maxHp, hp + value);
        cout << "Recovered HP: " << value << endl;
    }
    else if (item.getType() == "mp") {
        mp = min(maxMp, mp + value);
        cout << "Recovered MP: " << value << endl;
    }
    else if (item.getType() == "attack") {
        attackPower += value;
        cout << "Attack power increased by " << value << endl;
    }
    else {
        cout << "Nothing happened." << endl;
    }
}

bool Player::isAlive() const {
    return hp > 0;
}

void Player::addItem(const Item& item) {
    items.push_back(item);
}

void Player::addSkill(const Skill& skill) {
    skills.push_back(skill);
}

void Player::showStatus() const {
    cout << endl;
    cout << "----- Player Status -----" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << " / " << maxHp << endl;
    cout << "MP: " << mp << " / " << maxMp << endl;
    cout << "Attack: " << attackPower << endl;
    cout << "Gold: " << gold << endl;
    cout << "-------------------------" << endl;
}

void Player::showItems() const {
    cout << endl;
    cout << "----- Item List -----" << endl;
    for (int i = 0; i < static_cast<int>(items.size()); i++) {
        cout << i + 1 << ". ";
        items[i].showInfo();
    }
    cout << "---------------------" << endl;
}

void Player::showSkills() const {
    cout << endl;
    cout << "----- Skill List -----" << endl;
    for (int i = 0; i < static_cast<int>(skills.size()); i++) {
        cout << i + 1 << ". ";
        skills[i].showInfo();
    }
    cout << "----------------------" << endl;
}

void Player::gainGold(int amount) {
    gold += max(0, amount);
}

string Player::getName() const {
    return name;
}

int Player::getHp() const {
    return hp;
}

int Player::getMp() const {
    return mp;
}

int Player::getAttackPower() const {
    return attackPower;
}

int Player::getGold() const {
    return gold;
}

void Player::setName(const string& name) {
    this->name = name;
}

void Player::setHp(int hp) {
    this->hp = max(0, hp);
    this->maxHp = max(this->maxHp, this->hp);
}

void Player::setMp(int mp) {
    this->mp = max(0, mp);
    this->maxMp = max(this->maxMp, this->mp);
}

void Player::setAttackPower(int attackPower) {
    this->attackPower = max(0, attackPower);
}
