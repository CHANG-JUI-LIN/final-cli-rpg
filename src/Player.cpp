#include "Player.h"

#include <algorithm>
#include <iostream>


Player::Player()
{
    // Default starting values for a new player.
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
    // Normal attack does fixed damage based on attackPower.
    std::cout << name << " attacks for " << attackPower << " damage." << std::endl;
    return attackPower;
}

void Player::takeDamage(int damage) {
    // Keep HP from going below zero after taking damage.
    hp = std::max(0, hp - damage);
    std::cout << name << " takes " << damage << " damage. HP: " << hp << "/" << maxHp << std::endl;
}

void Player::useItem() {
    // If there is no item left, the player cannot recover HP.
    if (items.empty()) {
        std::cout << "No item can be used." << std::endl;
        return;
    }

    // Use the last item in the inventory and restore a fixed amount of HP.
    std::string itemName = items.back();
    items.pop_back();
    hp = std::min(maxHp, hp + 20);
    std::cout << name << " uses " << itemName << " and restores 20 HP. HP: " << hp << "/" << maxHp << std::endl;
}

bool Player::isAlive() const {
    // The player is alive as long as HP is greater than zero.
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
