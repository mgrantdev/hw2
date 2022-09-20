#ifndef BOOK_H
#define BOOK_H
#include "product.h"
#include "util.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Book : public Product
{
public:
    Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author);
    ~Book();

    /**
     * Returns the appropriate keywords that this product should be associated with
     */
    std::set<std::string> keywords() const
    {
        std::set<std::string> s1 = parseStringToWords(name_);
        std::set<std::string> s2 = parseStringToWords(author_);
        std::set<std::string> s3 = parseStringToWords(ISBN_);
        std::set<std::string> s4 = setUnion(s1, s2);
        std::set<std::string> s5 = setUnion(s4, s3);
        return s5;
    }

    /**
     * Returns a string to display the product info for hits of the search
     */
    std::string displayString() const {
         return name_ + "\nAuthor: " +  author_ + " ISBN: " + ISBN_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
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
           << ISBN_ << "\n"
           << author_ << std::endl;
    }

protected:
    std::string author_;
    std::string ISBN_;
};
#endif
