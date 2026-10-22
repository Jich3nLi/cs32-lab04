#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include "IceCreamItem.h"
#include <string>
#include <map>

class CustomItem : public IceCreamItem {
public:
    CustomItem(std::string size);
    virtual ~CustomItem();
    void addTopping(std::string topping);
    std::string composeItem() override;
    double getPrice() override;

private:
    std::map<std::string, int> toppings;
};

#endif
