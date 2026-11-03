#include "clothing.h"
#include <string>
#include <vector>

using namespace std;

Clothing::Clothing(string name, double price, int id, string material, string sex)
    : ShoppingItem(name, price, id), material(material), sex(sex) {}

string Clothing::getSpecializedInfo() const {
    return "Material: " + material + " | Sex: " + sex;
}

void Clothing::persist(std::ofstream& os) const{

    os  << "Clothing" << "|"
        << id << "|"
        << name << "|"
        << price << "|"
        << material << "|"
        << sex << "|" << std::endl;
}

ShoppingItem* Clothing::restore(const std::vector<std::string>& fields) {

    if (fields.size() < 6) {
        return nullptr;
    }

    int id = std::stoi(fields[1]);
    std::string name = fields[2];
    double price = std::stod(fields[3]);
    std::string material = fields[4];
    std::string sex =fields[5];

    return new Clothing(name, price, id, material, sex);
}