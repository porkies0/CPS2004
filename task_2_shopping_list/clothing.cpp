#include "clothing.h"
#include <string>

using namespace std;

Clothing::Clothing(string name, double price, int id, string material, string sex)
    : ShoppingItem(name, price, id), material(material), sex(sex) {}

string Clothing::getSpecializedInfo() const {
    return "Material: " + material + " | Sex: " + sex;
}