#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Skill.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getChoice() {
    int choice;
    cin >> choice;

    if (cin.fail()) {
        clearInput();
        return -1;
    }

    return choice;
}

int main() {
    cout << "==============================" << endl;
    cout << "      Final RPG Adventure      " << endl;
    cout << "==============================" << endl;

    string playerName;
    cout << "Please enter your hero name: ";
    getline(cin, playerName);

    if (playerName.empty()) {
        playerName = "Hero";
    }

    // Create the player and prepare basic skills/items.
    Player player(playerName, 120, 50, 18);
    player.addSkill(Skill("Fire Ball", 30, 10));
    player.addSkill(Skill("Thunder Strike", 45, 18));

    player.addItem(Item("Small Potion", "heal", 30, 3));
    player.addItem(Item("Mana Potion", "mp", 20, 2));
    player.addItem(Item("Power Stone", "attack", 5, 1));

    // The game uses a simple stage list. Defeat all monsters to win.
    vector<Monster> monsters;
    monsters.push_back(Monster("Slime", 60, 10, 20));
    monsters.push_back(Monster("Goblin", 90, 15, 35));
    monsters.push_back(Monster("Dark Dragon", 150, 22, 80));

    cout << endl;
    cout << "Welcome, " << player.getName() << "!" << endl;
    cout << "Defeat all monsters to win the game." << endl;

    for (int i = 0; i < static_cast<int>(monsters.size()); i++) {
        Monster& monster = monsters[i];

        cout << endl;
        cout << "==============================" << endl;
        cout << "A monster appears!" << endl;
        monster.showInfo();
        cout << "==============================" << endl;

        while (player.isAlive() && monster.isAlive()) {
            cout << endl;
            player.showStatus();
            player.showCombo();
            monster.showInfo();

            cout << endl;
            cout << "Choose your action:" << endl;
            cout << "1. Normal Attack" << endl;
            cout << "2. Use Skill" << endl;
            cout << "3. Use Item" << endl;
            cout << "4. Show Status" << endl;
            if (player.isComboFull()) {
                cout << "5. 🔥 Release Finisher" << endl;
            }
            cout << "Enter number: ";

            int choice = getChoice();

            if (choice == 1) {
                int damage = player.attack();
                monster.takeDamage(damage);
                player.addCombo();
            }
            else if (choice == 2) {
                player.showSkills();
                cout << "Choose skill number: ";
                int skillIndex = getChoice();

                int damage = player.useSkill(skillIndex - 1);
                if (damage > 0) {
                    monster.takeDamage(damage);
                    player.addCombo();
                }
                else {
                    continue;
                }
            }
            else if (choice == 3) {
                player.showItems();
                cout << "Choose item number: ";
                int itemIndex = getChoice();

                player.useItem(itemIndex - 1);
                player.resetCombo();
                continue;
            }
            else if (choice == 4) {
                player.showStatus();
                player.resetCombo();
                continue;
            }
            else if (choice == 5 && player.isComboFull()) {
                int damage = player.releaseFinisher();
                monster.takeDamage(damage);
            }
            else {
                cout << "Invalid input. Please choose again." << endl;
                continue;
            }

            if (!monster.isAlive()) {
                cout << endl;
                cout << monster.getName() << " was defeated!" << endl;
                cout << "You got " << monster.getRewardGold() << " gold." << endl;
                player.gainGold(monster.getRewardGold());
                break;
            }

            cout << endl;
            cout << monster.getName() << " attacks you!" << endl;
            int monsterDamage = monster.attack();
            player.takeDamage(monsterDamage);
        }

        if (!player.isAlive()) {
            cout << endl;
            cout << "==============================" << endl;
            cout << "Game Over!" << endl;
            cout << "You were defeated by the monster." << endl;
            cout << "==============================" << endl;
            return 0;
        }
    }

    cout << endl;
    cout << "==============================" << endl;
    cout << "Congratulations!" << endl;
    cout << "You defeated all monsters!" << endl;
    cout << "Final Gold: " << player.getGold() << endl;
    cout << "You win the game!" << endl;
    cout << "==============================" << endl;

    return 0;
}
