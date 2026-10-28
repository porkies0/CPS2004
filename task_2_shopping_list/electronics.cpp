#include "electronics.h"
#include <string>

using namespace std;

Electronics::Electronics(string name, double price, int id, string brand, int warrantyMonths)
    : ShoppingItem(name, price, id), brand(brand), warrantyMonths(warrantyMonths) {}

string Electronics::getSpecializedInfo() const {
    return "Brand: " + brand + " | Warranty: " + to_string(warrantyMonths) + " months";
}