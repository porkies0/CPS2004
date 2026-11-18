
#include <vector>
#include "shopping_items.h"
#include "book.h"
#include "toy.h"
#include "electronics.h"
#include "grocery.h"
#include "clothing.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

std::ostream& operator<<(std::ostream& os, const ShoppingItem& item) {
    item.persist(os);
    return os;
}

ShoppingItem* restore(std::istream& is) {
    std::string line;


    if (!std::getline(is, line)) {
        return nullptr; // Koniec súboru (EOF) alebo chyba čítania
    }

 
    std::vector<std::string> fields = parseLine(line);

    if (fields.empty()) {
        return nullptr;
    }


    std::string type = fields[0];
    std::istringstream iss(line);

 
    if (type == "Book") {
        auto* b = new Book("", 0, 0, "", 0, "");
        if (iss >> *b) return b;
        delete b;
    } else if (type == "Toy") {
        auto* t = new Toy("", 0, 0, "", 0);
        if (iss >> *t) return t;
        delete t;
    } else if (type == "Electronics") {
        auto* e = new Electronics("", 0, 0, "", 0);
        if (iss >> *e) return e;
        delete e;
    } else if (type == "Grocery") {
        auto* g = new Grocery("", 0, 0, "", 0);
        if (iss >> *g) return g;
        delete g;
    } else if (type == "Clothing") {
        auto* c = new Clothing("", 0, 0, "", "");
        if (iss >> *c) return c;
        delete c;
    }
    return nullptr;
}
