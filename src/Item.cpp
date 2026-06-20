#include "Item.h"

#include <algorithm>
#include <iostream>

using namespace std;

Item::Item() {
    name = "Potion";
    type = "heal";
    effectValue = 20;
    quantity = 1;
}

Item::Item(const string& name, const string& type, int effectValue, int quantity) {
    this->name = name;
    this->type = type;
    this->effectValue = max(0, effectValue);
    this->quantity = max(0, quantity);
}

int Item::use() {
    if (!isAvailable()) {
        cout << "No item left." << endl;
        return 0;
    }

    quantity--;
    cout << "Used item: " << name << endl;
    return effectValue;
}

void Item::showInfo() const {
    cout << name
         << " | Type: " << type
         << " | Effect: " << effectValue
         << " | Quantity: " << quantity
         << endl;
}

bool Item::isAvailable() const {
    return quantity > 0;
}

string Item::getName() const {
    return name;
}

string Item::getType() const {
    return type;
}

int Item::getEffectValue() const {
    return effectValue;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setName(const string& name) {
    this->name = name;
}

void Item::setType(const string& type) {
    this->type = type;
}

void Item::setEffectValue(int effectValue) {
    this->effectValue = max(0, effectValue);
}

void Item::setQuantity(int quantity) {
    this->quantity = max(0, quantity);
}
