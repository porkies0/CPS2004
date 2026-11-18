#include "grocery.h"
#include "electronics.h"
#include "clothing.h"
#include "book.h"
#include "toy.h"
#include "shopping_items.h"
#include "shopping_cart.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <utility>

template <typename T>
std::unique_ptr<ShoppingItem> readItem(const std::string& format, T empty) {
    std::cout << "Enter a line in this format:\n  " << format << "\n> ";
    if (std::cin >> empty) {
        return std::make_unique<T>(empty);
    }
    std::cin.clear();
    return nullptr;
}


void addFromTerminal(std::vector<std::unique_ptr<ShoppingItem>>& inventory) {
    std::cout << "Choose a type:\n"
              << "  1) Book\n  2) Toy\n  3) Electronics\n  4) Grocery\n  5) Clothing\n> ";

    std::string choice;
    if (!std::getline(std::cin, choice)) return;

    std::unique_ptr<ShoppingItem> item;

    if (choice == "1") {
        item = readItem("Book|id|name|price|isbn|pages|author|",
                        Book("", 0, 0, "", 0, ""));
    } else if (choice == "2") {
        item = readItem("Toy|id|name|price|material|min_age|",
                        Toy("", 0, 0, "", 0));
    } else if (choice == "3") {
        item = readItem("Electronics|id|name|price|brand|warranty_months|",
                        Electronics("", 0, 0, "", 0));
    } else if (choice == "4") {
        item = readItem("Grocery|id|name|price|expiration_date|weight_kg|",
                        Grocery("", 0, 0, "", 0));
    } else if (choice == "5") {
        item = readItem("Clothing|id|name|price|material|sex|",
                        Clothing("", 0, 0, "", ""));
    } else {
        std::cout << "Invalid choice.\n\n";
        return;
    }

    if (!item) {
        std::cout << "Invalid input, nothing was added.\n\n";
        return;
    }


    std::ofstream out("inventory.txt", std::ios::app);
    if (out.is_open()) {
        out << *item; 
    } else {
        std::cout << "Could not open the file.\n";
    }

    std::cout << "Added:\n";
    item->displayInfo();
    std::cout << item->getSpecializedInfo() << "\n\n";

    inventory.push_back(std::move(item));
}


int main () {
    
    std::vector<std::unique_ptr<ShoppingItem>> inventory; 


    std::string choice;
    while (true) {
        std::cout << "[a] add item, [q] quit: ";
        if (!std::getline(std::cin, choice) || choice == "q") break;

        if (choice == "a") {
            addFromTerminal(inventory);
        }
    }
    

    /*inventory.push_back(std::make_unique<Book>("Can't hurt me", 20.5, 3320, "1544512279", 364, "David Goggins"));
    inventory.push_back(std::make_unique<Toy>("Police Car", 8.3, 1100, "plastic", 3));
    inventory.push_back(std::make_unique<Electronics>("Computer", 1123, 9043, "Lenovo", 18));
    inventory.push_back(std::make_unique<Grocery>("Milk", 0.80, 4332, "1.1.2027", 0.8));
    inventory.push_back(std::make_unique<Clothing>("Jeans", 15, 2929, "denim", "Men"));
    */

    for (int i = 0; i < inventory.size(); ++i) {
        inventory[i]->displayInfo();
        std::cout << inventory[i]->getSpecializedInfo() << "\n";
        std::cout << "\n";
    }

    std::cout << "Direct Shopping Cart\n";
    
    auto book = std::make_unique<Book>("Can't hurt me", 20.5, 3320, "1544512279", 364, "David Goggins");

    auto jeans = std::make_unique<Clothing>("Jeans", 15, 2929, "denim", "Men");

    ShoppingCart myCart;
    myCart.addItem(std::move(book));
    myCart.addItem(std::move(jeans));

    myCart.displayCart();

    std::ofstream outFile("inventory.txt");
    if (outFile.is_open()) {
        for (const auto& item : inventory) {
            outFile << *item;
        }
}
    outFile.close();
    


    return 0;
}