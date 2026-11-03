#include "book.h"
#include <string>
#include <vector>

using namespace std;


Book::Book(string name, double price, int id, string isbn, int pages, string author)
    : ShoppingItem(name, price, id), isbn(isbn), pages(pages), author(author) {}

string Book::getSpecializedInfo() const {
    return ("Author: " + author + " | ISBN: " + isbn + " | Pages: " + to_string(pages));

}

void Book::persist(std::ofstream& os) const{

    os  << "Book" << "|"
        << id << "|"
        << name << "|"
        << price << "|"
        << isbn << "|"
        << pages << "|"
        << author << "|" << std::endl;
}


ShoppingItem* Book::restore(const std::vector<std::string>& fields) {

    if (fields.size() < 7) {
        return nullptr;
    }

    int id = std::stoi(fields[1]);
    std::string name = fields[2];
    double price = std::stod(fields[3]);
    std::string isbn = fields[4];
    int pages = std::stoi(fields[5]);
    std::string author = fields[6];

    return new Book(name, price, id, isbn, pages, author);
}