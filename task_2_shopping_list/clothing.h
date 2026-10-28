#include "shopping_items.h"
#include <string>


class Clothing : public ShoppingItem {

    private:
        std::string material;
        std::string sex;

    public:
        Clothing(std::string name, double price, int id, std::string material, std::string sex);

        std::string getSpecializedInfo() const override;
};
