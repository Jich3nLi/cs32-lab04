#include "PreMadeItem.h"
#include <string>
#include <cmath>

PreMadeItem::PreMadeItem(std::string name, std::string size) : IceCreamItem(size), name(name) {
    if (size == "small") {
        price = 4.00;
    } else if (size == "medium") {
        price = 6.00;
    } else if (size == "large") {
        price = 7.50;
    }
}

PreMadeItem::~PreMadeItem() {
}

double PreMadeItem::getPrice() {
    return price;
}

std::string PreMadeItem::composeItem() {
    std::string result = "";
    result += "Pre-made Size: " + size + "\n";
    result += "Pre-made Item: " + name + "\n";
    
    int cents = static_cast<int>(std::round(price * 100));
    result += "Price: $" + std::to_string(cents/100) + ".";
    int remainder = cents % 100;
    
    if (remainder < 10) {
        result += "0";
    }

    result += std::to_string(remainder) + "\n";

    return result;
}
