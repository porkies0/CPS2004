#include "book.h"
#include <string>
#include <vector>

using namespace std;


Book::Book(string name, double price, int id, string isbn, int pages, string author)
    : ShoppingItem(name, price, id), isbn(isbn), pages(pages), author(author) {}

string Book::getSpecializedInfo() const {
    return ("Author: " + author + " | ISBN: " + isbn + " | Pages: " + to_string(pages));

}

void Book::persist(std::ostream& os) const{

    os  << "Book" << "|"
        << id << "|"
        << name << "|"
        << price << "|"
        << isbn << "|"
        << pages << "|"
        << author << "|" << std::endl;
}


std::istream& operator>>(std::istream& is, Book& b) {
    std::string line;
    if (!std::getline(is, line)) {
        return is;
    }

    std::vector<std::string> f = parseLine(line);
    if (f.size() < 7 || f[0] != "Book") {
        is.setstate(std::ios::failbit);
        return is;
    }

    b.id     = std::stoi(f[1]);
    b.name   = f[2];
    b.price  = std::stod(f[3]);
    b.isbn   = f[4];
    b.pages  = std::stoi(f[5]);
    b.author = f[6];

    return is;
}