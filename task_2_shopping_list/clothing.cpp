#include "clothing.h"
#include <string>
#include <vector>

using namespace std;

Clothing::Clothing(string name, double price, int id, string material, string sex)
    : ShoppingItem(name, price, id), material(material), sex(sex) {}

string Clothing::getSpecializedInfo() const {
    return "Material: " + material + " | Sex: " + sex;
}

void Clothing::persist(std::ostream& os) const{

    os  << "Clothing" << "|"
        << id << "|"
        << name << "|"
        << price << "|"
        << material << "|"
        << sex << "|" << std::endl;
}

std::istream& operator>>(std::istream& is, Clothing& c) {
    std::string line;
    if (!std::getline(is, line)){
        return is;
    }
    auto f = parseLine(line);
    if (f.size() < 6 || f[0] != "Clothing") {
        is.setstate(std::ios::failbit);
        return is;
    }
    try {
        c.id = std::stoi(f[1]);  c.name = f[2];  c.price = std::stod(f[3]);
        c.material = f[4];       c.sex = f[5];
    } catch (const std::exception&) { is.setstate(std::ios::failbit); }
    return is;
}