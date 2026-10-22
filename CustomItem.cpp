#include "CustomItem.h"
#include <string>
#include <cmath>

CustomItem::CustomItem(std::string size) : IceCreamItem(size) {
    if (size == "small") {
        price = 3.00;
    } else if (size == "medium") {
        price = 5.00;
    } else if (size == "large") {
        price = 6.50;
    }
}

CustomItem::~CustomItem(){
}

void CustomItem::addTopping(std::string topping) {
    toppings[topping]++;
    price += 0.40;
}

double CustomItem::getPrice() {
    return price;
}

std::string CustomItem::composeItem() {
    std::string result = "";
    result += "Custom Size: " + size + "\n";
    result += "Toppings:\n";

    for (const auto& topping : toppings) {
        result += topping.first + ": ";
	result += std::to_string(topping.second) + " oz\n";
    }
    
    int cents = static_cast<int>(std::round(price * 100));
    result += "Price: $" + std::to_string(cents / 100) + ".";
    int remainder = cents % 100;

    if (remainder < 10) {
        result += "0";
    }

    result += std::to_string(remainder) + "\n";

    return result;
}
