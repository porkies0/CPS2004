#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <utility>

class Item {
public:
    Item(int value) : data(value) {}
    int getData() const { return data; }

private:
    int data;
};

class Container {
public:

    Container() : itemList(std::make_shared<std::list<Item>>()), name(""), size(0) {}


    Container(const Container& other)
    : itemList(other.itemList),
      name(other.name),
      size(other.size) {}


   Container& operator=(const Container& other) {
    if (this != &other) {
        itemList = other.itemList;
        name = other.name;
        size = other.size;
    }
    return *this;
    }


    Container(Container&& other) noexcept
        : itemList(std::move(other.itemList)),
          name(std::move(other.name)),
          size(other.size) {
        other.size = 0;
    }


    Container& operator=(Container&& other) noexcept {
        if (this != &other) {
            itemList = std::move(other.itemList);
            name = std::move(other.name);
            size = other.size;
            other.size = 0;
        }
        return *this;
    }


    ~Container() = default;


    void addItem(int value) {
        if (!itemList) {
            itemList = std::make_shared<std::list<Item>>();
        }
        itemList->push_back(Item(value));
        size++;
    }


    int getSize() const {
        return (itemList ? itemList->size() : 0);
    }


    void setName(const std::string& n) {
        name = n;
    }


    std::string getName() const {
        return name;
    }


    void displayItems() const {
        std::cout << "Container " << name << " contains " << (itemList ? itemList->size() : 0) << " items: ";
        if (itemList) {
            for (const Item& item : *itemList) {
                std::cout << item.getData() << "; ";
            }
        }
        std::cout << std::endl;
    }

private:
    std::shared_ptr<std::list<Item>> itemList;
    std::string name;
    int size;
};

int main() {
    Container container1;
    container1.setName("Box1");
    container1.addItem(1);
    container1.addItem(2);
    container1.addItem(3);


    Container containerCopy = container1;
    containerCopy.setName("BoxCopy");


    container1.addItem(4);

    container1.displayItems();
    containerCopy.displayItems();


    Container container2;
    container2 = container1;
    container2.setName("Box2");
    container2.displayItems();


    Container containerMove = std::move(container1);
    containerMove.setName("BoxMoved");
    containerMove.displayItems();
    container1.displayItems(); // empty after move

    return 0;
}