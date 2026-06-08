#ifndef ITEM_H
#define ITEM_H

#include<iostream>
#include<string>
class Item
{
private:
    std::string name;
    std::string type;
    int effectValue ;
    int quantity;
public:
    Item();
    ~Item();
    void use();
    void showInfo();
    bool isAvailable();
};




#endif 