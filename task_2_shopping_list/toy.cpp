#include "toy.h"
#include <string>
#include <vector>

using namespace std;

Toy::Toy(string name, double price, int id, string mat, int minimum_age)
    : ShoppingItem(name, price, id), material(mat), minimum_age(minimum_age) {}

string Toy::getSpecializedInfo() const {
    return "Material: " + material + " | Minimum Age: " + to_string(minimum_age) + "+";
}

void Toy::persist(std::ofstream& os) const{

    os  << "Toy" << "|"
        << id << "|"
        << name << "|"
        << price << "|"
        << material << "|"
        << minimum_age << "|" << std::endl;
}

ShoppingItem* Toy::restore(const std::vector<std::string>& fields) {

    if (fields.size() < 6) {
        return nullptr;
    }

    int id = std::stoi(fields[1]);
    std::string name = fields[2];
    double price = std::stod(fields[3]);
    std::string material = fields[4];
    int minAge = std::stoi(fields[5]);

    return new Toy(name, price, id, material, minAge);
}