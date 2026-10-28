#include "shopping_items.h"
#include <iostream>

using namespace std;

// Konštruktor
ShoppingItem::ShoppingItem(string n, double p, int i) 
    : name(n), price(p), id(i) {}


void ShoppingItem::displayInfo() const {
    cout << "Name: " << name << " | Price: $" << price << " | ID: " << id << " | \n";
}


string ShoppingItem::getName() const { 
    return name; 
}

double ShoppingItem::getPrice() const { 
    return price; 
}

int ShoppingItem::getId() const { 
    return id; 
}


void ShoppingItem::setName(const string& n) { 
    name = n; 
}

void ShoppingItem::setPrice(double p) { 
    price = p; 
}

void ShoppingItem::setId(int i) { 
    id = i; 
}