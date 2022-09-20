#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"
#include "util.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Clothing : public Product
{
public:
    Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
    ~Clothing();

    /**
     * Returns the appropriate keywords that this product should be associated with
     */
    std::set<std::string> keywords() const
    {
        std::set<std::string> s1 = parseStringToWords(name_);
        std::set<std::string> s2 = parseStringToWords(brand_);
        std::set<std::string> s3 = setUnion(s1, s2);
        return s3;
    }

    /**
     * Returns a string to display the product info for hits of the search
     */
    std::string displayString() const {
         return name_ + "\nSize: " +  size_ + " Brand: " + brand_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
    }

    /**
     * Outputs the product info in the database format
     */
    void dump(std::ostream &os) const
    {
        os << category_ << "\n"
           << name_ << "\n"
           << price_ << "\n"
           << qty_ << "\n"
           << size_ << "\n"
           << brand_ << std::endl;
    }

protected:
    std::string size_;
    std::string brand_;
};
#endif
