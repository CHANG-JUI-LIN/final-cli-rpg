#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "Item.h"
#include "Skill.h"

using namespace std;

class Player {
private:
    // Basic player status.
    string name;
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int attackPower;
    int gold;

    // Player inventory and learned skills.
    vector<Item> items;
    vector<Skill> skills;

public:
    Player();
    Player(const string& name, int hp, int mp, int attackPower);

    // Return normal attack damage.
    int attack() const;

    // Use a skill by index and return the damage dealt.
    int useSkill(int index);

    // Reduce player HP after a monster attack.
    void takeDamage(int damage);

    // Use an item by index and apply its effect to the player.
    void useItem(int index);

    // Check whether the player can continue fighting.
    bool isAlive() const;

    void addItem(const Item& item);
    void addSkill(const Skill& skill);
    void showStatus() const;
    void showItems() const;
    void showSkills() const;
    void gainGold(int amount);

    string getName() const;
    int getHp() const;
    int getMp() const;
    int getAttackPower() const;
    int getGold() const;

    void setName(const string& name);
    void setHp(int hp);
    void setMp(int mp);
    void setAttackPower(int attackPower);
};

#endif
