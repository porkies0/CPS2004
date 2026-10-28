#include "shopping_items.h"
#include <string>


class Grocery : public ShoppingItem {
private:
    std::string expDate;
    double weightKg;

public:
    Grocery(std::string name, double price, int id, std::string exp, double weight);
    
    std::string getSpecializedInfo() const override;
};
