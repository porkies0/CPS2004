#include "grocery.h"
#include "electronics.h"
#include "clothing.h"
#include "book.h"
#include "toy.h"

#include <iostream>


int main () {

    const int capacity = 5;

    ShoppingItem* inventory[capacity];

    inventory[0] = new Book("Can't hurt me", 20.5, 3320, "1544512279", 364, "David Goggins");
    inventory[1] = new Toy("Police Car", 8.3, 1100, "plastic", 3);
    inventory[2] = new Electronics("Computer", 1123, 9043, "Lenovo", 18);
    inventory[3] = new Grocery("Milk", 0.80, 4332, "1.1.2027", 0.8);
    inventory[4] = new Clothing("Jeans", 15, 2929, "denim", "Men");

    for (int i = 0; i < capacity; ++i) {
        inventory[i]->displayInfo();
        std::cout << inventory[i]->getSpecializedInfo() << "\n";
        std::cout << "\n";
    }

    for (int i = 0; i < capacity; ++i) {
        delete inventory[i];
    }

    return 0;
}