#include "grocery.h"
#include "electronics.h"
#include "clothing.h"
#include "book.h"
#include "toy.h"
#include "shopping_items.h"
#include <vector>
#include <iostream>
#include <fstream>

int main () {
    std::vector<ShoppingItem*> inventory; 


    std::ifstream inFile("inventory.txt");
    if (inFile.is_open()) {
        while (ShoppingItem* item = restore(inFile)) {
            inventory.push_back(item);
        }
        inFile.close();
    } else {
        std::cout << "No existing inventory file found. Starting fresh inventory...\n\n";
    }

    //inventory.push_back(new Book("Can't hurt me", 20.5, 3320, "1544512279", 364, "David Goggins"));
    //inventory.push_back(new Toy("Police Car", 8.3, 1100, "plastic", 3));
    //inventory.push_back(new Electronics("Computer", 1123, 9043, "Lenovo", 18));
    //inventory.push_back(new Grocery("Milk", 0.80, 4332, "1.1.2027", 0.8));
    //inventory.push_back(new Clothing("Jeans", 15, 2929, "denim", "Men"));
    

    for (int i = 0; i < inventory.size(); ++i) {
        inventory[i]->displayInfo();
        std::cout << inventory[i]->getSpecializedInfo() << "\n";
        std::cout << "\n";
    }

    std::ofstream outFile("inventory.txt");
    if (outFile.is_open()) {
    for (const auto& item : inventory) {
        item->persist(outFile);
    }
    outFile.close();
    }

    for (int i = 0; i < inventory.size(); ++i) {
        delete inventory[i];
    }

    return 0;
}