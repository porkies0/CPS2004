#include "shopping_items.h"
#include <string>
#include <vector>

class Toy : public ShoppingItem {

    private:
        std::string material;
        int minimum_age;
    
    public:
        Toy(std::string name, double price, int id, std::string material, int minimum_age);

        std::string getSpecializedInfo() const override;
        void persist(std::ostream& os) const override;
        friend std::istream& operator>>(std::istream& is, Toy& t);
};
