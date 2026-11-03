#include "grocery.h"
#include <string>
using namespace std;
#include <vector>

Grocery::Grocery(string name, double price, int id, string exp, double weight)
    : ShoppingItem(name, price, id), expDate(exp), weightKg(weight) {}


string Grocery::getSpecializedInfo() const {
    return "Expiration date: " + expDate + " | Weight: " + to_string(weightKg) + " kg";
}

void Grocery::persist(std::ofstream& os) const{

    os  << "Grocery" << "|"
        << id << "|"
        << name << "|"
        << price << "|"
        << expDate << "|"
        << weightKg << "|" << std::endl;
}

ShoppingItem* Grocery::restore(const std::vector<std::string>& fields) {

    if (fields.size() < 6) {
        return nullptr;
    }

    int id = std::stoi(fields[1]);
    std::string name = fields[2];
    double price = std::stod(fields[3]);
    std::string material = fields[4];
    double weightKg = std::stod(fields[5]);

    return new Grocery(name, price, id, material, weightKg);
}
