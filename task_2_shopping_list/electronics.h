#include "shopping_items.h"
#include <string>
#include <vector>

class Electronics : public ShoppingItem {

    private:
        std::string brand;
        int warrantyMonths;

    public:
        Electronics(std::string name, double price, int id, std::string brand, int warrantyMonths);

        std::string getSpecializedInfo() const override;
        void persist(std::ostream& os) const override;
        friend std::istream& operator>>(std::istream& is, Electronics& e);
};

