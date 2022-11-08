#include "user.h"
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}

void User::addProductToCart(Product* product) {
    cart.push_back(product);
}

std::vector<Product*> User::getCart() {
    return cart;
}

std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
    os.precision(2);
    os.setf(std::ios::fixed, std::ios::floatfield);
    os << name_ << " "  << balance_ << " " << type_ << endl;
}
