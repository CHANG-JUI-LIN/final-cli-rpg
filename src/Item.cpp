#include "Item.h"
#include <iostream>

using namespace std;

Item::Item() {
    name = "Potion";
    type = "heal";
    effectValue = 20;
    quantity = 1;
}

Item::Item(string name, string type, int effectValue, int quantity) {
    this->name = name;
    this->type = type;
    this->effectValue = effectValue;
    this->quantity = quantity;
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

void Item::showInfo() {
    cout << name
         << " | Type: " << type
         << " | Effect: " << effectValue
         << " | Quantity: " << quantity
         << endl;
}

bool Item::isAvailable() {
    return quantity > 0;
}

string Item::getName() {
    return name;
}

string Item::getType() {
    return type;
}

int Item::getEffectValue() {
    return effectValue;
}

int Item::getQuantity() {
    return quantity;
}

void Item::setName(string name) {
    this->name = name;
}

void Item::setType(string type) {
    this->type = type;
}

void Item::setEffectValue(int effectValue) {
    this->effectValue = effectValue;
}

void Item::setQuantity(int quantity) {
    this->quantity = quantity;
}
