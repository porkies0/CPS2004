#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "shopping_items.h"
#include <memory>
#include <vector>

class ShoppingCart {
private:
    std::vector<std::unique_ptr<ShoppingItem>> cart;

public:
    void addItem(std::unique_ptr<ShoppingItem> item);
    void displayCart() const;
};

#endif