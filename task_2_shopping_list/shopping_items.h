#ifndef SHOPPING_ITEMS_H
#define SHOPPING_ITEMS_H
#include <string>
#include <fstream>
#include <vector>

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
    // 0 sa rovna, ze to nemam implementovane v shopping_items.cpp
    virtual void persist(std::ostream& os) const = 0;

    std::string getName() const;
    double getPrice() const;
    int getId() const;


    void setName(const std::string& n);
    void setPrice(double p);
    void setId(int i);
};

std::vector<std::string> parseLine(const std::string& line);
std::ostream& operator<<(std::ostream& os, const ShoppingItem& item);

ShoppingItem* restore(std::istream& is);

#endif