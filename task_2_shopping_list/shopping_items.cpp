
#include <vector>
#include "shopping_items.h"
#include "book.h"
#include "toy.h"
#include "electronics.h"
#include "grocery.h"
#include "clothing.h"
#include <iostream>
#include <fstream>

using namespace std;


ShoppingItem::ShoppingItem(string n, double p, int i) 
    : name(n), price(p), id(i) {}


void ShoppingItem::displayInfo() const {
    cout << "Product: " << name << " | Price: $" << price << " | ID: " << id << " | \n";
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

std::vector<std::string> parseLine(const std::string& line) {
    std::vector<std::string> fields;
    std::string currentField = "";

    for (char c : line) {

        if (c == '\r') {
            continue;
        }
        
        if (c == '|') {
            fields.push_back(currentField);
            currentField = "";
        } else {
            // Inak pridávame znak do aktuálneho poľa
            currentField += c;
        }
    }

    fields.push_back(currentField);

    return fields;
}

ShoppingItem* restore(std::ifstream& is) {
    std::string line;


    if (!std::getline(is, line)) {
        return nullptr; // Koniec súboru (EOF) alebo chyba čítania
    }

 
    std::vector<std::string> fields = parseLine(line);

    if (fields.empty()) {
        return nullptr;
    }


    std::string typeId = fields[0];


    if (typeId == "Book") {
        return Book::restore(fields);
    } 
    else if (typeId == "Toy") {
        return Toy::restore(fields);
    } 
    else if (typeId == "Electronics") {
        return Electronics::restore(fields);
    } 
    else if (typeId == "Grocery") {
        return Grocery::restore(fields);
    } 
    else if (typeId == "Clothing") {
        return Clothing::restore(fields);
    }

    return nullptr;
}
