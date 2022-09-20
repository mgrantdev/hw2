#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "util.h"


class MyDataStore: public DataStore {
public:
    MyDataStore() {

    }
    ~MyDataStore() { 

    }

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p) {
        products.push_back(p);
    }

    /**
     * Adds a user to the data store
     */
    void addUser(User* u) {
        users.push_back(u);
    }

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type) {
        std::vector<Product*> results;
        std::set<std::string> termsSet;

        // convert terms vector to set
         for(std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); ++it) {
            termsSet.insert((*it));
         }

         for(std::vector<Product*>::iterator it = products.begin(); it != products.end(); ++it) {
            std::set<std::string> keywords = (*it)->keywords();

            // AND search
            if(type == 0 && setIntersection(keywords, termsSet).size() >= termsSet.size()) {
                results.push_back((*it));
            }
            
            // OR search
            if(type == 1 && setIntersection(keywords, termsSet).size() > 0) {
                // OR search
                results.push_back((*it));
            }
        }
        return results;
    }

    /*
    Retrieve user by their username
    */
    User* getUserByUsername(std::string username) {
        for(std::vector<User*>::iterator it = users.begin(); it != users.end(); ++it) {
            if((*it)->getName() == username) {
                return (*it);
            }
        }
        return nullptr;
    }

    /*
    Add a product to the given user's cart
    */
    void addToCart(User* user, Product* product) {
       user->addProductToCart(product);
    }
    
    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile) {
        for(std::vector<Product*>::iterator it = products.begin(); it != products.end(); ++it) {
            (*it)->dump(ofile);
        }
    }

    protected:
        std::vector<User*> users;
        std::vector<Product*> products;

};

#endif
