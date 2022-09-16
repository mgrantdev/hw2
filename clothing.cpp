#include <sstream>
#include <iomanip>
#include "product.h"
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) : Product(category, name, price, qty)
{
    size_ = size;
    brand_ = brand;
}

Clothing::~Clothing()
{

}