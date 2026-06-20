#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
    string name;
    string type;
    int effectValue;
    int quantity;

public:
    Item();
    Item(string name, string type, int effectValue, int quantity);

    int use();
    void showInfo();
    bool isAvailable();

    string getName();
    string getType();
    int getEffectValue();
    int getQuantity();

    void setName(string name);
    void setType(string type);
    void setEffectValue(int effectValue);
    void setQuantity(int quantity);
};

#endif
