#include "grocery.h"
#include <string>
using namespace std;
#include <vector>

Grocery::Grocery(string name, double price, int id, string exp, double weight)
    : ShoppingItem(name, price, id), expDate(exp), weightKg(weight) {}


string Grocery::getSpecializedInfo() const {
    return "Expiration date: " + expDate + " | Weight: " + to_string(weightKg) + " kg";
}

void Grocery::persist(std::ostream& os) const{

    os  << "Grocery" << "|"
        << id << "|"
        << name << "|"
        << price << "|"
        << expDate << "|"
        << weightKg << "|" << std::endl;
}


std::istream& operator>>(std::istream& is, Grocery& g) {
    std::string line;
    if (!std::getline(is, line)){
        return is;
    }
    auto f = parseLine(line);
    if (f.size() < 6 || f[0] != "Grocery") { 
        is.setstate(std::ios::failbit);
        return is;
    }
    try {
        g.id = std::stoi(f[1]);  g.name = f[2];  g.price = std::stod(f[3]);
        g.expDate = f[4];        g.weightKg = std::stod(f[5]);
    } catch (const std::exception&) { is.setstate(std::ios::failbit); }
    return is;
}
