#include "book.h"
#include <string>

using namespace std;


Book::Book(string name, double price, int id, string isbn, int pages, string author)
    : ShoppingItem(name, price, id), isbn(isbn), pages(pages), author(author) {}

string Book::getSpecializedInfo() const {
    return ("Author: " + author + " | ISBN: " + isbn + " | Pages: " + to_string(pages));
}