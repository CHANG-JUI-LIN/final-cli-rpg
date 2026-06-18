#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

class Player
{
private:
    // Basic player data used during the text RPG battle.
    std::string name;
    int hp;
    int maxHp;
    int attackPower;

    // Simple inventory list. The current version only stores potion names.
    std::vector<std::string> items;
public:
    Player();
    ~Player();

    // Returns the player's normal attack damage.
    int attack() const;

    // Reduces HP when the player is hit by a monster.
    void takeDamage(int damage);

    // Uses one item from the inventory if available.
    void useItem();

    // Checks whether the player can continue fighting.
    bool isAlive() const;

    // Getter functions for outside classes or the main battle loop.
    std::string getName() const;
    int getHp() const;
    int getAttackPower() const;
};




#endif
