#include "shopping_items.h"
#include <string>

class Toy : public ShoppingItem {

    private:
        std::string material;
        int minimum_age;
    
    public:
        Toy(std::string name, double price, int id, std::string material, int minimum_age);

        std::string getSpecializedInfo() const override;
};
