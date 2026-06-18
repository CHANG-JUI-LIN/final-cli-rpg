#include "Player.h"

#include <algorithm>
#include <iostream>


Player::Player()
{
    name = "Hero";
    hp = 100;
    maxHp = 100;
    attackPower = 15;
    items.push_back("Potion");
}

Player::~Player()
{
}

int Player::attack() const {
    std::cout << name << " attacks for " << attackPower << " damage." << std::endl;
    return attackPower;
}

void Player::takeDamage(int damage) {
    hp = std::max(0, hp - damage);
    std::cout << name << " takes " << damage << " damage. HP: " << hp << "/" << maxHp << std::endl;
}

void Player::useItem() {
    if (items.empty()) {
        std::cout << "No item can be used." << std::endl;
        return;
    }

    std::string itemName = items.back();
    items.pop_back();
    hp = std::min(maxHp, hp + 20);
    std::cout << name << " uses " << itemName << " and restores 20 HP. HP: " << hp << "/" << maxHp << std::endl;
}

bool Player::isAlive() const {
    return hp > 0;
}

std::string Player::getName() const {
    return name;
}

int Player::getHp() const {
    return hp;
}

int Player::getAttackPower() const {
    return attackPower;
}
