#include "shopping_items.h"
#include <string>

class Book : public ShoppingItem {

    private:
        std::string isbn;
        int pages;
        std::string author;

    public:
        Book(std::string name, double price, int id, std::string isbn, int pages, std::string author);


        std::string getSpecializedInfo() const override;

};

