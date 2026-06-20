#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
    // Item name shown in the inventory.
    string name;

    // Item type controls how Player::useItem applies the effect.
    // Supported values: heal, mp, attack.
    string type;

    // Amount of HP, MP, or attack value changed by this item.
    int effectValue;

    // Number of times this item can still be used.
    int quantity;

public:
    Item();
    Item(const string& name, const string& type, int effectValue, int quantity);

    // Consume one item and return its effect value.
    int use();

    // Display item information in the item menu.
    void showInfo() const;

    // Check whether the item still has quantity left.
    bool isAvailable() const;

    string getName() const;
    string getType() const;
    int getEffectValue() const;
    int getQuantity() const;

    void setName(const string& name);
    void setType(const string& type);
    void setEffectValue(int effectValue);
    void setQuantity(int quantity);
};

#endif
