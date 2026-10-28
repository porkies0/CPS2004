#include "grocery.h"
#include <string>
using namespace std;

Grocery::Grocery(string name, double price, int id, string exp, double weight)
    : ShoppingItem(name, price, id), expDate(exp), weightKg(weight) {}


string Grocery::getSpecializedInfo() const {
    return "Expiration date: " + expDate + " | Weight: " + to_string(weightKg) + " kg";
}
