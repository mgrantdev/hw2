#include <sstream>
#include <iomanip>
#include "product.h"
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string rating, const std::string genre) : Product(category, name, price, qty)
{
    rating_ = rating;
    genre_ = genre;
}

Movie::~Movie()
{

}