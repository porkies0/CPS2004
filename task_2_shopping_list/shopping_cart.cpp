#include "shopping_cart.h"
#include <iostream>
#include <utility>

void ShoppingCart::addItem(std::unique_ptr<ShoppingItem> item) {
    if (item) {
        cart.push_back(std::move(item));
    }
}

void ShoppingCart::displayCart() const {
    if (cart.empty()) {
        std::cout << "Cart is empty.\n";
        return;
    }

    for (const auto& itemPtr : cart) {
        itemPtr->displayInfo();
        std::cout << itemPtr->getSpecializedInfo() << "\n\n";
    }
}