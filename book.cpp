#include <sstream>
#include <iomanip>
#include "product.h"
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author) : Product(category, name, price, qty)
{
    author_ = author;
    ISBN_ = ISBN;
}

Book::~Book()
{

}