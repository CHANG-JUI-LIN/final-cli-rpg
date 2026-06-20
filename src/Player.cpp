#include "Player.h"
#include <iostream>
#include <algorithm>

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

Player::Player(string name, int hp, int mp, int attackPower) {
    this->name = name;
    this->hp = hp;
    this->maxHp = hp;
    this->mp = mp;
    this->maxMp = mp;
    this->attackPower = attackPower;
    this->gold = 0;
}

int Player::attack() {
    cout << name << " uses normal attack!" << endl;
    cout << "Damage: " << attackPower << endl;
    return attackPower;
}

int Player::useSkill(int index) {
    if (index < 0 || index >= skills.size()) {
        cout << "Invalid skill number." << endl;
        return 0;
    }

    Skill& skill = skills[index];

    if (mp < skill.getMpCost()) {
        cout << "Not enough MP!" << endl;
        return 0;
    }

    mp -= skill.getMpCost();
    return skill.use();
}

void Player::takeDamage(int damage) {
    hp -= damage;

    if (hp < 0) {
        hp = 0;
    }

    cout << name << " took " << damage << " damage." << endl;
}

void Player::useItem(int index) {
    if (index < 0 || index >= items.size()) {
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
        hp += value;
        if (hp > maxHp) {
            hp = maxHp;
        }

        cout << "Recovered HP: " << value << endl;
    }
    else if (item.getType() == "mp") {
        mp += value;
        if (mp > maxMp) {
            mp = maxMp;
        }

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

bool Player::isAlive() {
    return hp > 0;
}

void Player::addItem(Item item) {
    items.push_back(item);
}

void Player::addSkill(Skill skill) {
    skills.push_back(skill);
}

void Player::showStatus() {
    cout << endl;
    cout << "----- Player Status -----" << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << " / " << maxHp << endl;
    cout << "MP: " << mp << " / " << maxMp << endl;
    cout << "Attack: " << attackPower << endl;
    cout << "Gold: " << gold << endl;
    cout << "-------------------------" << endl;
}

void Player::showItems() {
    cout << endl;
    cout << "----- Item List -----" << endl;

    for (int i = 0; i < items.size(); i++) {
        cout << i + 1 << ". ";
        items[i].showInfo();
    }

    cout << "---------------------" << endl;
}

void Player::showSkills() {
    cout << endl;
    cout << "----- Skill List -----" << endl;

    for (int i = 0; i < skills.size(); i++) {
        cout << i + 1 << ". ";
        skills[i].showInfo();
    }

    cout << "----------------------" << endl;
}

void Player::gainGold(int amount) {
    gold += amount;
}

string Player::getName() {
    return name;
}

int Player::getHp() {
    return hp;
}

int Player::getMp() {
    return mp;
}

int Player::getAttackPower() {
    return attackPower;
}

int Player::getGold() {
    return gold;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setHp(int hp) {
    this->hp = hp;
}

void Player::setMp(int mp) {
    this->mp = mp;
}

void Player::setAttackPower(int attackPower) {
    this->attackPower = attackPower;
}
