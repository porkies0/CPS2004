#include "toy.h"
#include <string>

using namespace std;

Toy::Toy(string name, double price, int id, string mat, int minimum_age)
    : ShoppingItem(name, price, id), material(mat), minimum_age(minimum_age) {}

string Toy::getSpecializedInfo() const {
    return "Material: " + material + " | Minimum Age: " + to_string(minimum_age) + "+";
}