#include "electronics.h"
#include <string>
#include <vector>

using namespace std;

Electronics::Electronics(string name, double price, int id, string brand, int warrantyMonths)
    : ShoppingItem(name, price, id), brand(brand), warrantyMonths(warrantyMonths) {}

string Electronics::getSpecializedInfo() const {
    return "Brand: " + brand + " | Warranty: " + to_string(warrantyMonths) + " months";
}

void Electronics::persist(std::ostream& os) const{

    os  << "Electronics" << "|"
        << id << "|"
        << name << "|"
        << price << "|"
        << brand << "|"
        << warrantyMonths << "|" << std::endl;
}

std::istream& operator>>(std::istream& is, Electronics& e) {
    std::string line;
    if (!std::getline(is, line)){
        return is;
    }

    auto f = parseLine(line);
    if (f.size() < 6 || f[0] != "Electronics") { 
        is.setstate(std::ios::failbit); 
        return is; 
    }

    try {
        e.id = std::stoi(f[1]);  e.name = f[2];  e.price = std::stod(f[3]);
        e.brand = f[4];          e.warrantyMonths = std::stoi(f[5]);
    } catch (const std::exception&) { is.setstate(std::ios::failbit); }
    return is;
}