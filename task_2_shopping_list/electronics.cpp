#include "electronics.h"
#include <string>
#include <vector>

using namespace std;

Electronics::Electronics(string name, double price, int id, string brand, int warrantyMonths)
    : ShoppingItem(name, price, id), brand(brand), warrantyMonths(warrantyMonths) {}

string Electronics::getSpecializedInfo() const {
    return "Brand: " + brand + " | Warranty: " + to_string(warrantyMonths) + " months";
}

void Electronics::persist(std::ofstream& os) const{

    os  << "Electronics" << "|"
        << id << "|"
        << name << "|"
        << price << "|"
        << brand << "|"
        << warrantyMonths << "|" << std::endl;
}

ShoppingItem* Electronics::restore(const std::vector<std::string>& fields) {

    if (fields.size() < 6) {
        return nullptr;
    }

    int id = std::stoi(fields[1]);
    std::string name = fields[2];
    double price = std::stod(fields[3]);
    std::string material = fields[4];
    int weightKg = std::stoi(fields[5]);

    return new Electronics(name, price, id, material, weightKg);
}