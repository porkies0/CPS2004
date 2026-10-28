#ifndef SHOPPING_ITEMS_H
#define SHOPPING_ITEMS_H
#include <string>

class ShoppingItem {
protected:
    std::string name;
    double price;
    int id;

public:
    ShoppingItem(std::string name, double price, int id);
    virtual ~ShoppingItem() = default;

    virtual void displayInfo() const;
    virtual std::string getSpecializedInfo() const = 0;


    std::string getName() const;
    double getPrice() const;
    int getId() const;


    void setName(const std::string& n);
    void setPrice(double p);
    void setId(int i);
};

#endif