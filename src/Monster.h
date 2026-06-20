#ifndef MONSTER_H
#define MONSTER_H

#include <string>

using namespace std;

class Monster {
private:
    // Monster name shown during battle.
    string name;

    // Current monster health.
    int hp;

    // Fixed damage dealt by a normal monster attack.
    int attackPower;

    // Gold given to the player after this monster is defeated.
    int rewardGold;

public:
    Monster();
    Monster(const string& name, int hp, int attackPower, int rewardGold);

    // Return monster attack damage.
    int attack() const;

    // Reduce monster HP after the player attacks.
    void takeDamage(int damage);

    // Check whether the monster can continue fighting.
    bool isAlive() const;

    // Display current monster information.
    void showInfo() const;

    string getName() const;
    int getHp() const;
    int getAttackPower() const;
    int getRewardGold() const;

    void setName(const string& name);
    void setHp(int hp);
    void setAttackPower(int attackPower);
    void setRewardGold(int rewardGold);
};

#endif
