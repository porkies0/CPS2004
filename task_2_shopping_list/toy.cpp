#include "toy.h"
#include <string>
#include <vector>

using namespace std;

Toy::Toy(string name, double price, int id, string mat, int minimum_age)
    : ShoppingItem(name, price, id), material(mat), minimum_age(minimum_age) {}

string Toy::getSpecializedInfo() const {
    return "Material: " + material + " | Minimum Age: " + to_string(minimum_age) + "+";
}

void Toy::persist(std::ostream& os) const{

    os  << "Toy" << "|"
        << id << "|"
        << name << "|"
        << price << "|"
        << material << "|"
        << minimum_age << "|" << std::endl;
}

std::istream& operator>>(std::istream& is, Toy& t) {
    std::string line;
    if (!std::getline(is, line)) return is;
    auto f = parseLine(line);
    if (f.size() < 6 || f[0] != "Toy") { 
        is.setstate(std::ios::failbit); 
        return is; 
    }
    try {
        t.id = std::stoi(f[1]);  t.name = f[2];  t.price = std::stod(f[3]);
        t.material = f[4];       t.minimum_age = std::stoi(f[5]);
    } catch (const std::exception&) { is.setstate(std::ios::failbit); }
    return is;
}